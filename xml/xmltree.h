#ifndef XMLTREE_H
#define XMLTREE_H

#include <QObject>

class XmlElement;

class XmlTree : public QObject
{
    Q_OBJECT
public:
    explicit XmlTree(QObject *parent = 0);
    ~XmlTree();

    void setRoot(XmlElement *element);

    XmlElement* root();
    QList<XmlElement*> elements();

signals:
    
public slots:
    
private:
    XmlElement *m_root;

};

#endif // XMLTREE_H
