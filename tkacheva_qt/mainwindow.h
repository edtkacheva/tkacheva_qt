#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "mywidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
// class MyWidget;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString fileName;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void save();

    void on_actionSave_As_triggered();

    void on_actionEdit_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
