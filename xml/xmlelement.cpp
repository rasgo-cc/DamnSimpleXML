#include "xmlelement.h"

XmlElement::XmlElement(XmlElement *parentElement, QString name, QObject *parent) :
    QObject(parent),
    m_parentElement(parentElement),
    m_name(name)
{
}

QString XmlElement::name()
{
    return m_name;
}

QString XmlElement::valueStr()
{
    return m_value;
}

XmlElement* XmlElement::parentElement()
{
    return m_parentElement;
}

QList<XmlElement*> XmlElement::children()
{
    return m_children;
}

QList<XmlAttribute*> XmlElement::attributes()
{
    return m_attributes;
}

void XmlElement::setValue(const QString &value)
{
    m_value = value;
}

void XmlElement::setAttributes(QList<XmlAttribute *> attributes)
{
    m_attributes.clear();
    foreach(XmlAttribute *a, attributes)
        m_attributes.append(a);
}

void XmlElement::addChild(XmlElement *child)
{
    m_children.append(child);
}
