#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget{parent}
{

}


void MyWidget::paintEvent(QPaintEvent *event){
    QWidget::paintEvent(event);
    QPainter painter(this);
    QFont font("Times", 14);
    painter.setFont(font);
    QFontMetrics metrics(font);
    if (group.students.size() != 0) {
        int array_max[5];
        group.count_max(array_max);
        int y = 50;
        int x = 10;
        int dx = 5;
        painter.drawText(x, 20, QString::fromStdString("Имя"));
        x += array_max[0] + 2 * dx;
        painter.drawText(x, 20, QString::fromStdString("Фамилия"));
        x += array_max[1] + 2 * dx;
        painter.drawText(x, 20, QString::fromStdString("Возраст"));
        x += array_max[2] + 2 * dx;
        painter.drawText(x, 20, QString::fromStdString("Группа"));
        x += array_max[3] + 2 * dx;
        painter.drawText(x, 20, QString::fromStdString("Почта"));
        x += array_max[4] + dx;
        int ytable = 25;
        painter.drawLine(5, 5, x, 5);
        painter.drawLine(5, 5, 5, ytable + metrics.height() + 10);
        for (int i = 0; i < group.students.size() + 1; i++) {
            painter.drawLine(5, ytable, x, ytable);
            ytable += metrics.height() + 10;
        }
        ytable = 25;
        for (int i = 0; i < group.students.size(); i++) {
            painter.drawLine(5, ytable, 5, ytable + metrics.height() + 10);
            ytable += metrics.height() + 10;
        }
        ytable += metrics.height() + 10;
        int xtable = 10;
        for (int i = 0; i < 5; i++) {
            xtable += array_max[i] + dx;
            painter.drawLine(xtable, 5, xtable, ytable - (metrics.height() + 10));
            xtable += dx;
        }
        int total_width = xtable;
        int total_height = ytable;
        setMinimumSize(total_width, total_height);
        x = 10;
        group.draw(painter, &x, &y, array_max);
    }


}

void MyWidget::load(const QString& path)
{
    group.load(path);
}

void MyWidget::save(const QString& path)
{
    group.save(path);
}

void MyWidget::clean()
{
    group.students.clear();
    update();
}
