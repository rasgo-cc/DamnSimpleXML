#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QObject>

class XmlTree;

class XmlParser : public QObject
{
    Q_OBJECT
public:
    explicit XmlParser(QObject *parent = 0);
    ~XmlParser();

    XmlTree* xmlTree();

    XmlTree* read(const QString &fileName);
    
signals:
    
public slots:

private:
    XmlTree *m_tree;

    
};

#endif // XMLPARSER_H
