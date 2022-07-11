#include "operatepanel.h"
#include "ui_operatepanel.h"
#include "date_operator.h"
#include <QComboBox>
#include <cstring>
#include <QMessageBox>
#include "add_student_information.h"
#include <QFileDialog>
OperatePanel::OperatePanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OperatePanel)
{
    ui->setupUi(this);
    setWindowTitle("学生健康系统管理界面(作者:TXPH)");
    forbidden_text = new QLabel(this);
    total_text = new QLabel(this);
    total_text->setGeometry(860,430,121,31);
    forbidden_text->setGeometry(860,480,151,31);
    total_text->setText("总人数：0");
    forbidden_text->setText("待隔离人数：0");
    //设置total_text红色加粗
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    font.setPixelSize(20);
    total_text->setFont(font);
    total_text->setStyleSheet("color:red");
    //设置total_text点大小为13
    QFont ft;
    ft.setPointSize(13);
    total_text->setFont(ft);
    //设置forbidden_text红色加粗
    QFont forbidden_font;
    forbidden_font.setBold(true);
    forbidden_font.setWeight(75);
    forbidden_font.setPixelSize(20);
    forbidden_text->setFont(forbidden_font);
    forbidden_text->setStyleSheet("color:red");
    //设置forbidden_text点大小为13
    QFont forbidden_ft;
    forbidden_ft.setPointSize(13);
    forbidden_text->setFont(forbidden_ft);

    search_text = new QLineEdit(this);
    search_text->setGeometry(690,20,161,31);
    search_text->setPlaceholderText("学生姓名");
    //在Date添加当前日期
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy年M月dd日");
    ui->Date->addItem(str);
    
}

OperatePanel::~OperatePanel()
{
    delete ui;
}


void OperatePanel::on_del_student_clicked()
{
    emit delete_student();
}
void OperatePanel::on_search_clicked()
{   
    QString _name = search_text->text();
    emit search_student(_name);
}
void OperatePanel::on_Export_clicked()
{
    emit Export_student();
}






void OperatePanel::addData(QString yy,QString mm,QString dd)//添加日期信息
{
   QMessageBox MBox;//定义日期添加状态的窗口
   MBox.setWindowTitle("状态");
   if(yy!=NULL && mm!=NULL && dd!=NULL)
   {
       QString date="";
       date.append(yy);
       date.append("年");
       date.append(mm);
       date.append("月");
       date.append(dd);
       date.append("日");
       ui->Date->addItem(date);
       QString message = "成功添加:";
       message.append(date);
       MBox.setText(message);
       agreeBut = MBox.addButton("确认", QMessageBox::AcceptRole);
       MBox.exec();
             
                     
   }
   else
   {
       QString message = "请您输入完整的日期!";
       MBox.setText(message);
       resetBut = MBox.addButton("重新输入", QMessageBox::RejectRole);
       MBox.exec();
   }


}
void OperatePanel::Get_student_information(QString grade,QString name,QString sex,QString id ,double temp,QString result)
{
    QMessageBox MBox;//定义学生添加状态的窗口
    MBox.setWindowTitle("状态");
    int rowcount = ui->tables->rowCount();
    if(grade!=NULL && name!=NULL && sex!=NULL && sex!=NULL && id!=NULL && temp!=0 && result!=NULL)
    {
        ui->tables->insertRow(rowcount);
        ui->tables->setItem(rowcount,0,new QTableWidgetItem(grade));
        ui->tables->item(rowcount,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tables->setItem(rowcount,1,new QTableWidgetItem(name));
        ui->tables->item(rowcount,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tables->setItem(rowcount,2,new QTableWidgetItem(sex));
        ui->tables->item(rowcount,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tables->setItem(rowcount,3,new QTableWidgetItem(id));
        ui->tables->item(rowcount,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        QString str_temp = QString::number(temp);//double 转 QString
        QTableWidgetItem *st_temp = new QTableWidgetItem(str_temp);
        if(temp>37.3) st_temp->setTextColor(QColor(255,0,0));//判断温度是否大于阈值
        ui->tables->setItem(rowcount,4,st_temp);
        ui->tables->item(rowcount,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        QTableWidgetItem *st_result = new QTableWidgetItem(result);
        if(result=="阳性") st_result->setTextColor(QColor(255,0,0));//判断核酸结果是否正常
        ui->tables->setItem(rowcount,5,st_result);
        ui->tables->item(rowcount,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        if(temp>37.3||result=="阳性") forbidden_num++;//判断是否需要隔离

        QString message = "成功添加:";
        message.append(grade);
        message.append(" ");
        message.append(name);
        MBox.setText(message);
        agreeBut = MBox.addButton("确认", QMessageBox::AcceptRole);
        MBox.exec();
        int new_total = ui->tables->rowCount();
        total_text->setText("总人数："+QString::number(new_total));
        forbidden_text->setText("待隔离人数："+QString::number(forbidden_num));
        
    }
    else
    {
        QString message = "请您输入完整的学生信息!";
        MBox.setText(message);
        resetBut = MBox.addButton("重新输入", QMessageBox::RejectRole);
        MBox.exec();
    }


}
void OperatePanel::del_stu()
{
    
    int row = ui->tables->currentRow();
    if(row==-1) QMessageBox::warning(this,"警告","当前没有学生信息，请添加！！！");
    else
    {   
        
        QMessageBox MBox;
        MBox.setWindowTitle("状态");
        QString message = "成功删除:";
        message.append(ui->tables->item(row,1)->text());
        MBox.setText(message);
        agreeBut = MBox.addButton("确认", QMessageBox::AcceptRole);
        MBox.exec();
        //把删除行的temp转化成double
        QString temp = ui->tables->item(row,4)->text();
        double temp_double = temp.toDouble();
        //判断删除行的temp的数值是否大于阈值和result是否正常
        if(temp_double>37.3||ui->tables->item(row,5)->text()=="阳性")
        {
            forbidden_num--;
            forbidden_text->setText("待隔离人数："+QString::number(forbidden_num));
        }
        //将选中的行删除
        ui->tables->removeRow(row);
        int new_total = ui->tables->rowCount();
        total_text->setText("总人数："+QString::number(new_total));
        
    }
    
}


void OperatePanel::search_stu(QString _name)
{
    //根据姓名查询学生，如果存在就引导到所在行；如果不存在就提示查询的学生不存在
    int rowcount = ui->tables->rowCount();
    for(int i=0;i<rowcount;i++)
    {
        if(ui->tables->item(i,1)->text()==_name)
        {
            ui->tables->selectRow(i);
            return;
        }
    }
    QMessageBox::warning(this,"警告","查询的学生不存在！！！");
    
    
}
void OperatePanel::Export_stu() //把tables连同表头一起导出为excel
{   

    QString fileName = QFileDialog::getSaveFileName(this, tr("导出学生信息"),
                                                    "",
                                                    tr("Excel Files (*.xlsx)"));
    if(fileName.isEmpty()) return;
    
    
    QAxObject *excel = new QAxObject(this);
    excel->setControl("Excel.Application");
    excel->dynamicCall("SetVisible (bool Visible)","false");
    excel->setProperty("DisplayAlerts", false);
    QAxObject *workbooks = excel->querySubObject("WorkBooks");
    workbooks->dynamicCall("Add");
    QAxObject *workbook = excel->querySubObject("ActiveWorkBook");
    QAxObject *worksheets = workbook->querySubObject("Sheets");
    QAxObject *worksheet = worksheets->querySubObject("Item(int)", 1);
    for(int i=0;i<ui->tables->rowCount();i++)
    {   
        for(int j=0;j<ui->tables->columnCount();j++)
        {   
            
            QAxObject *cell = worksheet->querySubObject("Cells(int,int)",i+1,j+1);
            cell->setProperty("Value",ui->tables->item(i,j)->text());
            cell->setProperty("HorizontalAlignment",-4108);
        }

    }
    
    workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(fileName));
    workbook->dynamicCall("Close()");
    excel->dynamicCall("Quit()");
    delete excel;
    QMessageBox MBox;
    MBox.setWindowTitle("状态");
    QString message = "成功导出:";
    message.append(fileName);
    MBox.setText(message);
    agreeBut = MBox.addButton("确认", QMessageBox::AcceptRole);
    MBox.exec();
       
}   

