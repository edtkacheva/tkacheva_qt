#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets>
#include <QDialog>
#include <QListWidget>
#include "mywidget.h"

class Dialog_add;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    tkacheva_group group;
    MyWidget* widget;
    QListWidget* getlist();
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void FillBox(int index);
    void setWidget(MyWidget *widget);
    void updateMainView();
    static void deleteLayout(QLayout* layout);

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
