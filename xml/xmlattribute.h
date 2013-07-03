#ifndef XMLATTRIBUTE_H
#define XMLATTRIBUTE_H

#include <QObject>

class XmlElement;

class XmlAttribute : public QObject
{
    Q_OBJECT
public:
    explicit XmlAttribute(XmlElement *element, QString name, QString value = QString(), QObject *parent = 0);
    QString name();
    QString valueStr();


signals:
    
public slots:

private:
    XmlElement *m_element;
    QString m_name;
    QString m_valueStr;
    
};

#endif // XMLATTRIBUTE_H
