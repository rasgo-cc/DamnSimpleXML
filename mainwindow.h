#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class XmlParser;
class XmlTreeWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void slotBrowseFile();
    void slotUpdateXmlTree();
    void slotReplace();
    void slotFind(const QString &text);
    void slotFindPrev();
    void slotFindNext();
    
private:
    Ui::MainWindow *ui;

    void parseXmlFile(const QString &filePath);

    XmlParser *m_parser;
    XmlTreeWidget *m_treeWidget;
};

#endif // MAINWINDOW_H
