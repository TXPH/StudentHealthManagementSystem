#ifndef DATE_OPERATOR_H
#define DATE_OPERATOR_H
#include <cstring>
#include <QWidget>
#include <QLineEdit>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
namespace Ui {
class Date_Operator;
}

class Date_Operator : public QWidget
{
    Q_OBJECT

signals:

    void sendData(QString yy,QString mm,QString dd);//用于发送日期数据

public:
    explicit Date_Operator(QWidget *parent = nullptr);

    ~Date_Operator();

public slots:

    void create()//生成操作界面的槽函数
    {
        this->show();
    }

    void on_add_clicked();


private:
    Ui::Date_Operator *ui;
    QLineEdit *year_text; //输入年份
    QLineEdit *month_text;//输入月份
    QLineEdit *day_text; //输入日子
};

#endif // DATE_OPERATOR_H
