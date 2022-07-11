#include "date_operator.h"
#include "ui_date_operator.h"
#include <QDebug>
Date_Operator::Date_Operator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Date_Operator)
{
    ui->setupUi(this);
    setWindowTitle("添加日期");
    //QPushButton add(this);//定义日期增加按钮
    year_text = new QLineEdit(this);//输入年份
    year_text->setGeometry(30,40,61,31);
    month_text = new QLineEdit(this);//输入月份
    month_text->setGeometry(170,40,61,31);
    day_text = new QLineEdit(this);//输入日子
    day_text->setGeometry(330,40,61,31);
}

Date_Operator::~Date_Operator()
{
    delete ui;
}
void Date_Operator::on_add_clicked()
{
    QString yy = year_text->text();
    QString mm = month_text->text();
    QString dd = day_text->text();
    emit sendData(yy,mm,dd);
}

