#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    on_comboBox_currentIndexChanged(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_comboBox_currentIndexChanged(int index)
{
    QString url = QString("qrc:/html/view%1.html").arg(index+1);
    ui->webview1->load(QUrl(url));
}
