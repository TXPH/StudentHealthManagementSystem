#include "MainWidget.h"
menu_widget::menu_widget() //主界面窗口类
{
    welcome_text = new QLabel(this);
    id_text = new QLabel(this);
    pass_text = new QLabel(this);
    Login_ID = new QLineEdit(this);
    Login_PASS = new QLineEdit(this);
    setWindowTitle("学生每日健康登记系统(作者:TXPH)");
    setFont(QFont("宋体",17));
    this->resize(900,500);
    welcome_text->setText("欢迎使用学生每日健康登记系统");
    welcome_text->setAlignment(Qt::AlignHCenter);
    welcome_text->setStyleSheet("QLabel{font:40px;color:red;background-color:rgb(f9,f9,f9);}");
    welcome_text->setGeometry(150,50,600,600);
    id_text->setText("管理员账号：");
    id_text->setGeometry(150,5,500,425);
    pass_text->setText("管理员密码：");
    pass_text->setGeometry(150,100,500,425);
    Login_ID->move(350,205);
    Login_ID->setPlaceholderText("请输入...");
    Login_ID->setClearButtonEnabled(true);
    Login_PASS->move(350,295);
    Login_PASS->setPlaceholderText("请输入...");
    Login_PASS->setClearButtonEnabled(true);
    Login_PASS->setEchoMode(QLineEdit::Password);

}
menu_widget::~menu_widget()
{
    delete welcome_text;
    delete Login_ID;
    delete id_text;
    delete pass_text;
    delete Login_PASS;

}

