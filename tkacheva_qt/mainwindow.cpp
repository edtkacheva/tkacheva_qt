#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mywidget.h"

#include <QFileDialog>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_actionSave_triggered()
{
    if(fileName.isEmpty())
        on_actionSave_As_triggered();
    else
        save();
}

void MainWindow::on_actionOpen_triggered()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Открыть"), QDir::currentPath(), tr("Текстовый файл (*.txt)"));
    if (!fileName.isEmpty()){
        std::cout << "text1";
        ui->myWidget->load(fileName);
        ui->myWidget->onSetHeight(600);
        ui->myWidget->onSetHeight(800);
    }
}

void MainWindow::on_actionNew_triggered()
{
    ui->myWidget->clean();
    fileName = "";
}

void MainWindow::save()
{
    ui->myWidget->save(fileName);
}

void MainWindow::on_actionSave_As_triggered()
{
    fileName = QFileDialog::getSaveFileName(this, tr("Открыть"), QDir::currentPath(), tr("Текстовый файл (*.txt)"));
    if (!fileName.isEmpty())
        save();
}

