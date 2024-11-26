#include "dialog_add.h"
#include "ui_dialog_add.h"

Dialog_add::Dialog_add(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_add)
{
    ui->setupUi(this);
    on_checkBox_2_checkStateChanged(Qt::Unchecked);
}

Dialog_add::~Dialog_add()
{
    delete ui;
}

void Dialog_add::on_pushButton_clicked()
{
    student->add();
    dialog->widget->group.students.push_back(student);
    dialog->getlist()->addItem(QString::fromLocal8Bit(student->last_name));
    dialog->getlist()->setCurrentRow(dialog->widget->group.students.size() - 1);
    this->close();
}

void Dialog_add::on_checkBox_2_checkStateChanged(const Qt::CheckState &arg1)
{
    if (arg1 == Qt::Checked){
        shared_ptr<tkacheva_headman> student = std::make_shared<tkacheva_headman>();
        this->student = student;
        student->name = "Ivan";
        student->last_name = "Ivanov";
        student->age = 20;
        student->group_name = "AX-XX-XX";
        student->email = "mail@gmail.ru";
        Dialog::deleteLayout(ui->formLayout);
        student->drawLabels(this, ui->formLayout, false);
    }
    else {
        shared_ptr<tkacheva_student> student = std::make_shared<tkacheva_student>();
        this->student = student;
        student->name = "Ivan";
        student->last_name = "Ivanov";
        student->age = 20;
        Dialog::deleteLayout(ui->formLayout);
        student->drawLabels(this,ui->formLayout, false);
    }
}

void Dialog_add::EditStudent(int index){
    ui->pushButton->hide();
    QPushButton* button = new QPushButton(this);
    connect(button, &QPushButton::clicked, this, &Dialog_add::on_pushButton_clicked_Edit);
    button->setText("Редактировать");
    ui->formLayout_2->addWidget(button);
    button->show();
    student = dialog->widget->group.students[index];
    Dialog::deleteLayout(ui->formLayout);
    student->drawLabels(this, ui->formLayout, false);
    ui->checkBox_2->hide();
}

void Dialog_add::on_pushButton_clicked_Edit()
{
    student->add();
    this->close();
}
