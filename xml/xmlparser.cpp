#include "xmlparser.h"

#include "xmltree.h"
#include "xmlelement.h"
#include "xmlattribute.h"

#include <QDebug>

#include <QFile>
#include <QXmlStreamReader>

XmlParser::XmlParser(QObject *parent) :
    QObject(parent)
{
    m_tree = new XmlTree(this);
}

XmlParser::~XmlParser()
{
    delete m_tree;
}

XmlTree* XmlParser::xmlTree()
{
    return m_tree;
}

XmlTree* XmlParser::read(const QString &fileName)
{
    unsigned int level = 0;
    XmlElement *element;
    static XmlElement *lastElement;
    QVector<XmlElement *> parent;
    QList<XmlAttribute*> al;
    QString value;

    parent.reserve(64); // reserve space for parents/sublevels/subelements

    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Unable to read XML file:" << file.errorString();
        return false;
    }

    QXmlStreamReader xml(&file);

    while(!xml.atEnd() && !xml.hasError())
    {
        xml.readNext();
        switch(xml.tokenType())
        {
        case QXmlStreamReader::StartElement:
            qDebug() << level << xml.name().toString();
            element = new XmlElement(0, xml.name().toString());
            al.clear();
            foreach(QXmlStreamAttribute a, xml.attributes().toList()) {
                al.append(new XmlAttribute(element, a.name().toString(), a.value().toString()));
            }
            element->setAttributes(al);
            if(level == 0)
                m_tree->setRoot(element);
            else {
                parent[level-1]->addChild(element);
            }
            parent[level] = element;
            lastElement = element;
            level++;
            break;
        case QXmlStreamReader::EndElement:
            level--;
            break;
        case QXmlStreamReader::Characters:
            if(!xml.isWhitespace()) {
                lastElement->setValue(xml.text().toString());
            }
            break;
        default: ;
        }
    }

    if(xml.hasError())
    {
        qDebug() << "XML error:" << xml.errorString();
        return false;
    }

    return m_tree;
}
