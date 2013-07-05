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
    //ui->statusBar->hide();

    ui->filePath_lineEdit->hide();

    m_parser = new XmlParser();
    //m_treeWidget = new XmlTreeWidget(this);
    m_treeWidget = ui->treeWidget;
    m_treeWidget->setTree(m_parser->xmlTree());

    connect(ui->browse_pushButton, SIGNAL(clicked()),
            this, SLOT(slotBrowseFile()));
    connect(ui->refresh_pushButton, SIGNAL(clicked()),
            this, SLOT(slotReplace()));
    connect(ui->find_lineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(slotFind(QString)));
    connect(ui->findNext_toolButton, SIGNAL(clicked()),
            this, SLOT(slotFindNext()));
    connect(ui->findPrev_toolButton, SIGNAL(clicked()),
            this, SLOT(slotFindPrev()));

    setWindowTitle("DamnSimpleXML");
}

void MainWindow::slotBrowseFile()
{
    QString path = QFileDialog::getOpenFileName(this, "Open .xml file", "", "*.xml");
    ui->filePath_lineEdit->setText(path);
    slotReplace();
}

void MainWindow::slotUpdateXmlTree()
{
    m_treeWidget->slotReload();
}

void MainWindow::slotReplace()
{
    QString path = ui->filePath_lineEdit->text();
    parseXmlFile(path);
    slotUpdateXmlTree();
}

void MainWindow::slotFind(const QString &text)
{
    if(text != "" && text.count() > 2)
        m_treeWidget->slotFind(text);
}

void MainWindow::slotFindNext()
{
    m_treeWidget->slotFindNext();
}

void MainWindow::slotFindPrev()
{
    m_treeWidget->slotFindPrev();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::parseXmlFile(const QString &filePath)
{
    if(m_parser->read(filePath) != 0) {
        ui->statusBar->showMessage(filePath);
    }

}
