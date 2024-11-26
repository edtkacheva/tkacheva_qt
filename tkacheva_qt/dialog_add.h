#ifndef DIALOG_ADD_H
#define DIALOG_ADD_H

#include "dialog.h"

namespace Ui {
class Dialog_add;
}

class Dialog_add : public QDialog
{
    Q_OBJECT

public:
    shared_ptr<tkacheva_student> student;
    Dialog* dialog = qobject_cast<Dialog*>(this->parent());
    explicit Dialog_add(QWidget *parent = nullptr);
    ~Dialog_add();
    void EditStudent(int index);
    void on_pushButton_clicked_Edit();
private slots:
    void on_pushButton_clicked();

    // void on_checkBox_checkStateChanged(const Qt::CheckState &arg1);

    void on_checkBox_2_checkStateChanged(const Qt::CheckState &arg1);

private:
    Ui::Dialog_add *ui;
};

#endif // DIALOG_ADD_H
