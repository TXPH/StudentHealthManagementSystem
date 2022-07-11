#include "add_student_information.h"
#include "ui_add_student_information.h"

Add_student_information::Add_student_information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_student_information)
{
    ui->setupUi(this);
    setWindowTitle("学生信息界面");
    grade_text = new QLineEdit(this);//输入班级
    grade_text->setGeometry(130,20,191,31);
    name_text = new QLineEdit(this);//输入姓名
    name_text->setGeometry(130,80,191,31);
    id_text = new QLineEdit(this);//输入学号
    id_text->setGeometry(130,200,191,31);
    temperature_text = new QLineEdit(this);//输入温度
    temperature_text->setGeometry(130,260,191,31);


}

Add_student_information::~Add_student_information()
{
    delete ui;
}

void Add_student_information::on_Add_clicked()//定义增加学生信息槽函数函数
{
    QString grade = grade_text->text();
    QString name = name_text->text();
    QString sex="";
    if(ui->sex_0->isChecked()) sex.append("男");
    else if (ui->sex_1->isChecked()) sex.append("女");
    QString id = id_text->text();
    QString temp_s = temperature_text->text();
    double temp = temp_s.toDouble();
    QString result ="";
    if(ui->result0->isChecked()) result.append("阳性");
    else if (ui->result1->isChecked()) result.append("阴性");
    emit Send_student_information(grade,name,sex,id,temp,result);
}
