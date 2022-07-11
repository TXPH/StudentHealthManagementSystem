#ifndef WIDGET_H
#define WIDGET_H
#include <QLineEdit>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
//#include <QDebug>
#include <QMessageBox>
class menu_widget : public QWidget //从QWidget继承了一个主界面的窗口类
{
    Q_OBJECT
signals:
  void show_operate();//展示操作界面

public:
    menu_widget();
    ~menu_widget();
private:
    QLabel *welcome_text; //定义指向文本框的指针
    QLabel *id_text;//定义指向管理员账号文本
    QLabel *pass_text;//定义指向管理员密码
    QLineEdit *Login_ID;//定义指向管理员账号输入框的指针
    QLineEdit *Login_PASS;//定义指向管理员密码输入框的指针
    const char *admin_id = "admin"; //初始化管理员账号
    const char *admin_pass = "admin"; //初始化管理员密码
    QPushButton *agreeBut; //登陆成功进入管理界面按钮
    QPushButton *resetBut;//登陆失败重新输入按钮

public slots:
    void Judge(){
        QMessageBox MBox;//定义登陆状态的窗口
        MBox.setWindowTitle("登录状态");
        if(Login_ID->text()=="admin" && Login_PASS->text()=="admin")
        {
            MBox.setText("管理员登录成功！");
            agreeBut = MBox.addButton("进入", QMessageBox::AcceptRole);
            MBox.exec();
            this->hide();
            emit show_operate();

        }
        else
        {
            MBox.setText("账号或密码错误！");
            resetBut = MBox.addButton("重新输入", QMessageBox::RejectRole);
            MBox.exec();

        }

    }
};
#endif // WIDGET_H
