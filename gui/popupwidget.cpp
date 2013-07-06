#include "popupwidget.h"
#include "ui_popupwidget.h"

PopupWidget::PopupWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupWidget)
{
    ui->setupUi(this);
}

PopupWidget::~PopupWidget()
{
    delete ui;
}
