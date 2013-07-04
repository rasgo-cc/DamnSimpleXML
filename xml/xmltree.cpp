#include "xmltree.h"
#include "xmlelement.h"


XmlTree::XmlTree(QObject *parent) :
    QObject(parent),
    m_root(0)
{
}

XmlTree::~XmlTree()
{

}

XmlElement* XmlTree::root()
{
    return m_root;
}

void XmlTree::setRoot(XmlElement *element)
{
    m_root = element;
}


QList<XmlElement*> XmlTree::elements()
{
    //TODO get a list of all elements in the tree
    return QList<XmlElement*>();
}
