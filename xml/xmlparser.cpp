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
    //static XmlElement *lastStartElement;

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
            //element = new XmlElement(0, xml.name().toString());
            //if(m_tree->root() == 0)
                //m_tree->setRoot(element);
            level++;
            break;
        case QXmlStreamReader::EndElement:
            level--;
            break;
        default: ;
        }
    }


    /*QString pName = xml.attributes().at(0).value().toString();
           Label *pLabel = new Label(pName);
           qDebug() << pName;

           int leafs = xml.attributes().at(1).value().toString().toInt();
           while(leafs-- > 0)
           {
               xml.readNextStartElement(); // level=1

               QString sName = xml.attributes().at(0).value().toString();
               Label *sLabel = new Label(sName);
               qDebug() << sName;
               sLabel->setTop(pLabel);
               pLabel->addLeaf(sLabel);

               xml.skipCurrentElement();
           }

           addTopLabel(pLabel);*/

    if(xml.hasError())
    {
        qDebug() << "XML error:" << xml.errorString();
        return false;
    }


    return m_tree;
}
