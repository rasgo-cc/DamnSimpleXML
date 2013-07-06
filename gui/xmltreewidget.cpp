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
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
        if(column == 0)
            header()->setSectionResizeMode(column, QHeaderView::ResizeToContents);
        else
            header()->setSectionResizeMode(column, QHeaderView::Interactive);
#else
        if(column == 0)
            header()->setResizeMode(column, QHeaderView::ResizeToContents);
        else
            header()->setResizeMode(column, QHeaderView::Interactive);
#endif
    }
}

void XmlTreeWidget::setTree(XmlTree *tree)
{
    m_tree = tree;
}

void XmlTreeWidget::slotReload()
{
    clear();
    if(m_tree != 0) {
        if(m_tree->root() != 0) {
            updateTree(m_tree->root(), 0);
            topLevelItem(0)->setExpanded(true);
        }
    }
}

void XmlTreeWidget::slotFind(const QString &text)
{
    QList<QTreeWidgetItem*> il;
    int col;
    for(col=0; col < columnCount(); col++)
            il.append(findItems(text, Qt::MatchContains |  Qt::MatchRecursive, col));
    m_foundItems = il;
    if(!il.isEmpty()) {
        setCurrentItem(il.first());
    }
}

void XmlTreeWidget::slotFindPrev()
{
    int iCur, iPrev;
    iCur = m_foundItems.indexOf(currentItem());
    if(iCur != -1 && iCur > 0) {
        iPrev = iCur-1;
        setCurrentItem(m_foundItems.at(iPrev));
    }
}

void XmlTreeWidget::slotFindNext()
{
    int iCur, iNext;
    iCur = m_foundItems.indexOf(currentItem());
    if(iCur != -1 && iCur < m_foundItems.count()-1) {
        iNext = iCur+1;
        setCurrentItem(m_foundItems.at(iNext));
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
    if(parent == 0) {
        insertTopLevelItem(0, widgetItem);
        m_root.element = element;
        m_root.widget = widgetItem;
    }
    else {
        parent->addChild(widgetItem);
    }

    foreach(XmlElement *e, element->children()) {
        updateTree(e, widgetItem);
    }
}
