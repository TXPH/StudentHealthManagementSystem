#ifndef ADD_STUDENT_INFORMATION_H
#define ADD_STUDENT_INFORMATION_H
#include <QGroupBox>
#include <QDialog>
#include <QLineEdit>
namespace Ui {
class Add_student_information;
}

class Add_student_information : public QDialog
{
    Q_OBJECT
signals:
    void Send_student_information(QString grade,QString name,QString sex,QString id ,double temp,QString result);
public slots:
    void create()//学生信息添加界面的槽函数
    {
        this->show();
    }
    void on_Add_clicked();
public:
    explicit Add_student_information(QWidget *parent = nullptr);
    ~Add_student_information();

private:
    Ui::Add_student_information *ui;
    QLineEdit *grade_text; //输入班级
    QLineEdit *name_text;//输入姓名
    QLineEdit *id_text;//输入学号
    QLineEdit *temperature_text;//输入温度


};

#endif // ADD_STUDENT_INFORMATION_H
