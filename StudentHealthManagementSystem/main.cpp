#include "date_operator.h"
#include "MainWidget.h"
#include "operatepanel.h"
#include "add_student_information.h"
#include <QApplication>
#include <QTableWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu_widget main_menu; //登陆界面
    OperatePanel operater;//管理员操作界面
    Date_Operator date_operator;//日期操作界面
    Add_student_information student_information;//添加学生信息的界面
    QPushButton Login_but("登录",&main_menu); //登录按钮
    Login_but.setGeometry(700,220,100,100);//对登录按钮进行设置
    main_menu.show();//展示登录操作界面
    QPushButton add_date; //编辑日期的按钮
    QComboBox Date;//日期框
    QPushButton add;//日期操作界面的添加按钮
    QPushButton add_student;//添加学生信息的按钮
    QTableWidget table;//添加当前学生信息列表
    QPushButton Add;//学生信息的添加按钮
    QPushButton del_student;//学生信息的删除按钮
    QPushButton search;//学生信息的查询按钮
    QPushButton Export;//导出学生信息的按钮


    

    //判断用户登录
    QObject::connect(&Login_but,&QPushButton::clicked,&main_menu, &menu_widget::Judge);
    //判断用户登录
    QObject::connect(&main_menu,&menu_widget::show_operate,&operater, &OperatePanel::create);
    //添加日期弹窗
    QObject::connect(&add_date,&QPushButton::clicked,&operater,&OperatePanel::on_add_date_clicked);
    QObject::connect(&operater,&OperatePanel::show_date_operate,&date_operator, &Date_Operator::create);
    //用于添加日期信息
    QObject::connect(&add,&QPushButton::clicked,&date_operator,&Date_Operator::on_add_clicked);
    QObject::connect(&date_operator,&Date_Operator::sendData,&operater,&OperatePanel::addData);
    //添加学生信息弹窗
    QObject::connect(&add_student,&QPushButton::clicked,&operater,&OperatePanel::on_add_student_clicked);
    QObject::connect(&operater,&OperatePanel::show_add_student_information_operate,&student_information,&Add_student_information::create);
    //用于添加学生信息
    QObject::connect(&Add,&QPushButton::clicked,&student_information,&Add_student_information::on_Add_clicked);
    QObject::connect(&student_information,&Add_student_information::Send_student_information,&operater,&OperatePanel::Get_student_information);
    //删除学生信息
    QObject::connect(&del_student,&QPushButton::clicked,&operater,&OperatePanel::on_del_student_clicked);
    QObject::connect(&operater,&OperatePanel::delete_student,&operater,&OperatePanel::del_stu);
    //查询学生信息
    QObject::connect(&search,&QPushButton::clicked,&operater,&OperatePanel::on_search_clicked);
    QObject::connect(&operater,&OperatePanel::search_student,&operater,&OperatePanel::search_stu);
    //导出学生信息
    QObject::connect(&Export,&QPushButton::clicked,&operater,&OperatePanel::on_Export_clicked);
    QObject::connect(&operater,&OperatePanel::Export_student,&operater,&OperatePanel::Export_stu);

    return a.exec();
}
