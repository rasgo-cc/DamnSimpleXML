#include "xmltree.h"
#include "xmlelement.h"


XmlTree::XmlTree(QObject *parent) :
    QObject(parent),
    m_root(0)
{
    // "Dummy" tree
    XmlElement *element;
    m_root = new XmlElement(0, "root");

    int cnt1, cnt2, j=2, k=3;
    for(cnt1=0; cnt1 < j; cnt1++) {
        element = new XmlElement(m_root, QString().sprintf("elem_j_%d",cnt1));
        m_root->addChild(element);
        for(cnt2=0; cnt2 < k; cnt2++) {
            element->addChild( new XmlElement(m_root, QString().sprintf("elem_k_%d",cnt1)) );
        }
    }
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
