#include "xmltreewidget.h"

#include "xmltree.h"
#include "xmlelement.h"
#include "xmlattribute.h"

#include <QDebug>
#include <QHeaderView>
#include <QTreeWidgetItem>

XmlTreeWidget::XmlTreeWidget(QWidget *parent) :
    QTreeWidget(parent)
{
    int column;
    for(column = 0; column < columnCount(); column++) {
        if(column == 0)
            header()->setResizeMode(column, QHeaderView::ResizeToContents);
        else
            header()->setResizeMode(column, QHeaderView::Interactive);
    }
}

void XmlTreeWidget::setTree(XmlTree *tree)
{
    m_tree = tree;
}

void XmlTreeWidget::slotRefresh()
{
    clear();
    if(m_tree != 0) {
        if(m_tree->root() != 0) {
            updateTree(m_tree->root(), 0);
            topLevelItem(0)->setExpanded(true);
        }
    }
}

QString XmlTreeWidget::buildAttributeString(QList<XmlAttribute*> list)
{
    QString str("");
    foreach(XmlAttribute *a, list) {
        str.append(a->name() + QString("=\"") + a->valueStr() + QString("\" "));
    }
    return str;
}

void XmlTreeWidget::updateTree(XmlElement *element, QTreeWidgetItem *parent)
{
    QTreeWidgetItem *widgetItem;

    QStringList strList;
    strList.append(element->name());
    strList.append(element->valueStr());
    //qDebug() << "attr of" << element->name() << ":" << buildAttributeString(element->attributes());
    strList.append(buildAttributeString(element->attributes()));
    widgetItem = new QTreeWidgetItem(parent, QStringList(strList));
    widgetItem->setExpanded(true);
    if(parent == 0)
        insertTopLevelItem(0, widgetItem);
    else {
        parent->addChild(widgetItem);
    }

    foreach(XmlElement *e, element->children()) {
        updateTree(e, widgetItem);
    }
}
