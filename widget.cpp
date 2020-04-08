#include "widget.h"
#include "ui_widget.h"

#include <QVariantMap>
#include <QJsonDocument>
#include <QDateTime>
#include <QtMath>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    qsrand(QDateTime::currentDateTime().toTime_t());

    on_comboBox_currentIndexChanged(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_comboBox_currentIndexChanged(int index)
{
    ui->pushButton->setVisible(index == 0);

    QString url = QString("qrc:/html/view%1.html").arg(index+1);
    ui->webview1->load(QUrl(url));
}

void Widget::on_pushButton_clicked()
{
    QVariantMap map;
    QVariantList varList1,varList2;

    for(int i=0;i<7;++i) {
        varList1 << (qrand() % 1000 );
        varList2 << (qrand() % 1000 );
    }

    map["series1"] = varList1;
    map["series2"] = varList2;

    QJsonDocument doc = QJsonDocument::fromVariant(map);
    QString str = doc.toJson(QJsonDocument::Compact);
    str.replace(QRegExp("\""), "\\\"");
    QString strVal = QString("setDatas(\"%1\");").arg(str);

    ui->webview1->page()->runJavaScript(strVal);
}
