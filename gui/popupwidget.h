#ifndef POPUPWIDGET_H
#define POPUPWIDGET_H

#include <QWidget>

namespace Ui {
class PopupWidget;
}

class PopupWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit PopupWidget(QWidget *parent = 0);
    ~PopupWidget();
    
private:
    Ui::PopupWidget *ui;
};

#endif // POPUPWIDGET_H
