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

XmlElement* XmlElement::parentElement()
{
    return m_parentElement;
}

QList<XmlElement*> XmlElement::children()
{
    return m_children;
}

void XmlElement::addChild(XmlElement *child)
{
    m_children.append(child);
}
