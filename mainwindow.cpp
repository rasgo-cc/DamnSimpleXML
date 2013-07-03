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
    ui->mainToolBar->hide();
    ui->statusBar->hide();

    m_parser = new XmlParser();
    //m_treeWidget = new XmlTreeWidget(this);
    m_treeWidget = ui->treeWidget;

    connect(ui->browse_pushButton, SIGNAL(clicked()),
            this, SLOT(slotBrowseFile()));
    connect(ui->refresh_pushButton, SIGNAL(clicked()),
            m_treeWidget, SLOT(slotRefresh()));

    setWindowTitle("DamnXML");
}

void MainWindow::slotBrowseFile()
{
    QString path = QFileDialog::getOpenFileName(this, "Open .xml file", "", "*.xml");
    ui->filePath_lineEdit->setText(path);
    m_parser->read(path);
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
