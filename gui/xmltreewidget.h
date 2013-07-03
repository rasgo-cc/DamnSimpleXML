#ifndef XMLTREEWIDGET_H
#define XMLTREEWIDGET_H

#include <QTreeWidget>

class XmlTree;
class XmlElement;

class XmlTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit XmlTreeWidget(QWidget *parent = 0);

    void setTree(XmlTree *tree); //FIXME put this in the constructor (issue: this is a "promoted widget")

signals:
    
public slots:
    void slotRefresh();
    
    void updateTree(XmlElement *element);

private:
    XmlTree *m_tree;
};

#endif // XMLTREEWIDGET_H
