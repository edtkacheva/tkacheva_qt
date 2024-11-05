#include "tkacheva_headman.h"

void tkacheva_headman::show(ostream& out) {
    tkacheva_student::show(cout);
    out << "Название группы: " << group_name << endl
        << "Почта старосты: " << email << endl;
}

void tkacheva_headman::create(istream& in) {
    tkacheva_student::create(cin);
    cin.ignore();
    cout << "Введите название группы: ";
    getline(in, group_name);
    cout << "Введите почту старосты: ";
    getline(in, email);
}

void tkacheva_headman::show_on_screen(QPainter& painter,int* x, int* y, int* array_lens) {
    *x = 10;
    QFont font("Times", 14);
    QFontMetrics metrics(font);
    int dx = 50;
    painter.drawText(*x, *y, QString::fromLocal8Bit(name));
    *(x) += array_lens[0] + dx;
    painter.drawText(*x, *y, QString::fromLocal8Bit(last_name));
    *(x) += array_lens[1] + dx;
    painter.drawText(*x, *y, QString::fromLocal8Bit(to_string(age)));
    *(x) += array_lens[2] + dx;
    painter.drawText(*x, *y, QString::fromLocal8Bit(group_name));
    *(x) += array_lens[3] + dx;
    painter.drawText(*x, *y, QString::fromLocal8Bit(email));
    *(y) += metrics.height() + 10;
}

int* tkacheva_headman::count_len() {
    QFont font("Times", 14);
    QFontMetrics metrics(font);
    int name_w = metrics.boundingRect(QString::fromStdString(name)).width();
    int last_name_w = metrics.boundingRect(QString::fromStdString(last_name)).width();
    int age_w = metrics.boundingRect(QString::fromStdString(to_string(age))).width();
    int group_name_w = metrics.boundingRect(QString::fromStdString(group_name)).width();
    int email_w = metrics.boundingRect(QString::fromStdString(email)).width();
    int array_lens[5];
    array_lens[0] = max(name_w, metrics.boundingRect(QString::fromStdString("Имя")).width());
    array_lens[1] = max(last_name_w, metrics.boundingRect(QString::fromStdString("Фамилия")).width());
    array_lens[2] = max(age_w, metrics.boundingRect(QString::fromStdString("Возраст")).width());
    array_lens[3] = max(group_name_w, metrics.boundingRect(QString::fromStdString("Группа")).width());
    array_lens[4] = max(email_w, metrics.boundingRect(QString::fromStdString("Почта")).width());
    return array_lens;
}
