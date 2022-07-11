#ifndef OPERATEPANEL_H
#define OPERATEPANEL_H
#include <QPushButton>
#include <QDialog>
#include <QComboBox>
#include <QDateTime>
#include <QTime>
#include <QTableWidget>
#include <QFile>
#include <QTextEdit>
#include <QLabel>
#include <QAxObject>
#include <QTextStream>
namespace Ui {
class OperatePanel;
}

class OperatePanel : public QDialog
{
    Q_OBJECT
signals:
  void show_date_operate(); //展示日期操作界面的信号函数
  void show_add_student_information_operate();//展示学生信息添加界面的信号函数
  void delete_student();//删除学生信息的信号函数
  void search_student(QString _name);//查询学生信息的信号函数
  void Export_student();//导出学生信息的信号函数
public:
    explicit OperatePanel(QWidget *parent = nullptr);
    ~OperatePanel();
public slots:
    void create()//生成操作界面的槽函数
    {
        this->show();
    }

    void on_add_date_clicked() //点击释放日期操作界面的槽函数
    {
        emit show_date_operate();
    }
    void addData(QString yy,QString mm,QString dd);//用于接收日期数据并添加
    void Get_student_information(QString grade,QString name,QString sex,QString id ,double temp,QString result);
    void on_add_student_clicked()//点击释放学生信息添加界面的槽函数
    {
        emit show_add_student_information_operate();
    }
    void on_del_student_clicked();//点击删除学生信息的槽函数
    void del_stu();//删除学生信息的槽函数
    void on_search_clicked();//点击查询学生信息的槽函数
    void search_stu(QString _name);//查询学生信息的槽函数
    void on_Export_clicked();//点击导出学生信息的槽函数
    void Export_stu();//导出学生信息的槽函数

private:
    Ui::OperatePanel *ui;
    QPushButton *agreeBut; //添加成功
    QPushButton *resetBut;//添加失败
    QLabel *total_text;//统计总人数文本
    QLabel *forbidden_text;// 统计待隔离人数文本
    int forbidden_num=0;//待隔离人数
    QLineEdit *search_text;//搜索框
    
};

#endif // OPERATEPANEL_H
