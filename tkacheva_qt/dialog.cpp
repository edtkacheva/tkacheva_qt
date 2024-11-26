#include "dialog.h"
#include "ui_dialog.h"
#include "dialog_add.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setWidget(MyWidget *widget) {
    this->widget = widget;
}

void Dialog::FillBox(int index) {
    // tkacheva_group group = widget->group;
    // deleteLayout(ui->formLayout);
    // if (!group.students.empty()){
    //     std::for_each(group.students.begin(), group.students.end(), [this](std::shared_ptr<tkacheva_student> student){
    //         this->ui->listWidget->addItem(QString::fromLocal8Bit(student->last_name));
    //     });
    //     this->ui->listWidget->setCurrentRow(0);
    // }
    tkacheva_group group = widget->group;
    if (!group.students.empty()){
        std::for_each(group.students.begin(), group.students.end(), [this](std::shared_ptr<tkacheva_student> student){
            this->ui->listWidget->addItem(QString::fromLocal8Bit(student->last_name));
        });
        this->ui->listWidget->setCurrentRow(index);
    }
}

void Dialog::deleteLayout(QLayout* layout) {
    while (QLayoutItem* item = layout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->setParent(nullptr);
        }
        delete item;
    }
}

void Dialog::on_pushButton_3_clicked()
{
    if (!widget->group.students.empty()){
        int index1 = ui->listWidget->currentRow();
        Dialog_add *dialog = new Dialog_add(this);
        dialog->EditStudent(index1);
        int result = dialog->exec();
        deleteLayout(ui->formLayout);
        ui->listWidget->clear();
        FillBox(index1);
    }
}

void Dialog::on_pushButton_2_clicked()
{
    int index = ui->listWidget->currentRow();
    if (!widget->group.students.empty()){
        if (index != 0 && index == widget->group.students.size()){
            index--;
        }
        if (widget->group.students.size() == 1){
            widget->group.students.erase(widget->group.students.begin() + index);
            ui->listWidget->clear();
        }
        else{
            delete ui->listWidget->takeItem(index);
            widget->group.students.erase(widget->group.students.begin() + index);
        }
    }
    else {
        ui->pushButton_2->setDisabled(true);
    }

}


void Dialog::on_pushButton_clicked()
{
    Dialog_add *dialog = new Dialog_add(this);
    int result = dialog->exec();
}


void Dialog::on_pushButton_4_clicked()
{
    close();
}


void Dialog::on_listWidget_currentRowChanged(int currentRow)
{
    deleteLayout(ui->formLayout);
    if (currentRow >= 0 && currentRow < widget->group.students.size()) {
        widget->group.students[currentRow]->drawLabels(this, ui->formLayout, true);
    }
}

QListWidget* Dialog::getlist() {
    return ui->listWidget;
}
