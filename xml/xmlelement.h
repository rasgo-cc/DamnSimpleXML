#ifndef XMLELEMENT_H
#define XMLELEMENT_H

#include <QObject>

class XmlAttribute;

class XmlElement : public QObject
{
    Q_OBJECT
public:
    explicit XmlElement(XmlElement *parentElement, QString name, QObject *parent = 0);
    
    void addAttribute(XmlAttribute *attribute);
    void addAttributes(QList<XmlAttribute*> attributes);
    void addChild(XmlElement *child);
    void addChildren(QList<XmlElement*> children);

    QString name();
    XmlElement *parentElement();
    QList<XmlAttribute*> attributes();
    QList<XmlElement*> children();

signals:
    
public slots:

private:
    XmlElement *m_parentElement;
    QString m_name;
    QList<XmlAttribute*> m_attributes;
    QList<XmlElement*> m_children;
    
};

#endif // XMLELEMENT_H
