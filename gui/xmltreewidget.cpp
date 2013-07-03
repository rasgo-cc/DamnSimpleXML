#include "xmltreewidget.h"

#include "xmltree.h"
#include "xmlelement.h"

#include <QDebug>
#include <QHeaderView>
#include <QTreeWidgetItem>

XmlTreeWidget::XmlTreeWidget(QWidget *parent) :
    QTreeWidget(parent)
{
    header()->close();
    setColumnCount(1);
//    QList<QTreeWidgetItem *> items;
//    for (int i = 0; i < 10; ++i)
//        items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i))));
//    insertTopLevelItems(0, items);
}

void XmlTreeWidget::setTree(XmlTree *tree)
{
    m_tree = tree;
}

void XmlTreeWidget::slotRefresh()
{
    qDebug() << "XmlTreeWidget::slotRefresh()";
    if(m_tree != 0) {
        /*if(m_tree->root() != 0) {
            updateTree(m_tree->root());
        }*/
    }
}

void XmlTreeWidget::updateTree(XmlElement *element)
{
    qDebug() << "XmlTreeWidget::update()";
    /*static XmlElement *lastElement;
    static QTreeWidgetItem *lastWidget;
    static unsigned int level = 0;

    QTreeWidgetItem *widgetItem;*/

    /*if(element->parentElement() == 0) // root
    {
        qDebug() << "asd";
        widgetItem = new QTreeWidgetItem(this, QStringList(element->name()));
        insertTopLevelItem(0, widgetItem);
    }*/


}
