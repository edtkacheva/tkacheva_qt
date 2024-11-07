#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget{parent}
{

}

void MyWidget::paintEvent(QPaintEvent *event){
    QWidget::paintEvent(event);
    QPainter painter(this);
    // QTextLayout textLayout;
    QFont font("Times", 14);
    painter.setFont(font);
    QFontMetrics metrics(font);
    if (group.students.size()!=0){
        int array_max[5];
        group.count_max(array_max);
        int y = 50;
        int x = 10;
        int dx = 50;
        painter.drawText(x, 20, QString::fromStdString("Имя"));
        x += array_max[0] + dx;
        painter.drawText(x, 20, QString::fromStdString("Фамилия"));
        x += array_max[1] + dx;
        painter.drawText(x, 20, QString::fromStdString("Возраст"));
        x += array_max[2] + dx;
        painter.drawText(x, 20, QString::fromStdString("Группа"));
        x += array_max[3] + dx;
        painter.drawText(x, 20, QString::fromStdString("Почта"));
        x += array_max[4] + dx;
        int ytable = 25;
        for (int i = 0; i < group.students.size() + 1; i++){
            painter.drawLine(0, ytable, x, ytable);
            ytable += metrics.height() + 10;
        }

        int xtable = 10;
        for (int i = 0; i < 5; i++){
            xtable += array_max[i] + dx;
            painter.drawLine(xtable, 0, xtable, ytable - (metrics.height() + 10));
        }
        int total_width = xtable;
        int total_height = ytable;
        setMinimumSize(total_width, total_height);
        x = 10;
        group.draw(painter,&x,&y, array_max);
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
void MyWidget::onSetWidth(int w)
{
    resize(w, height());
    repaint();
}

void MyWidget::onSetHeight(int h)
{
    resize(width(), h);
    repaint();
}
