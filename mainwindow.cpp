#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "xmlparser.h"
#include "xmltree.h"
#include "xmltreewidget.h"

#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuBar->hide();
    ui->mainToolBar->hide();
    ui->statusBar->hide();

    ui->filePath_lineEdit->hide();

    m_parser = new XmlParser();
    //m_treeWidget = new XmlTreeWidget(this);
    m_treeWidget = ui->treeWidget;
    m_treeWidget->setTree(m_parser->xmlTree());

    connect(ui->browse_pushButton, SIGNAL(clicked()),
            this, SLOT(slotBrowseFile()));

    setWindowTitle("DamnXML");
}

void MainWindow::slotBrowseFile()
{
    QString path = QFileDialog::getOpenFileName(this, "Open .xml file", "", "*.xml");
    ui->filePath_lineEdit->setText(path);
    m_parser->read(path);
    slotUpdateXmlTree();
}

void MainWindow::slotUpdateXmlTree()
{
    m_treeWidget->slotRefresh();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::parseXmlFile(const QString &filePath)
{
    m_parser->read(filePath);
}
