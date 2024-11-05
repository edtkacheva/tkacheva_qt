#include "tkacheva_student.h"
#include "header.h"
#include "boost.h"

using namespace std;

BOOST_CLASS_IMPLEMENTATION(tkacheva_student, boost::serialization::level_type::object_serializable);

void tkacheva_student::create(istream& in)
{
    cout << "Введите имя студента: ";
    in >> ws;
    getline(in, name);
    cout << "Введите фамилию студента: ";
    in >> ws;
    getline(in, last_name);
    cout << "Введите возраст студента: ";
    getcorrectnumber(age);
    while (age <= 0) {
        cout << "Некорректный ввод! Повторите попытку." << endl;
        getcorrectnumber(age);
    }
}

void tkacheva_student::show(ostream& out)
{
    out << "Студент:" << endl;
    out << "Имя студента: " << name << endl
        << "Фамилия студента: " << last_name << endl
        << "Возраст студента: " << age << endl;
}

void tkacheva_student::show_on_screen(QPainter& painter,int* x, int* y, int* array_lens) {
    *x = 10;
    QFont font("Times", 14);
    QFontMetrics metrics(font);
    int dx = 50;
    painter.drawText(*x, *y, QString::fromLocal8Bit(name));
    *(x) += array_lens[0] + dx;
    painter.drawText(*x, *y, QString::fromLocal8Bit(last_name));
    *(x) += array_lens[1] + dx;
    painter.drawText(*x, *y, QString::fromLocal8Bit(to_string(age)));
    *(y) += metrics.height() + 10;
}

int* tkacheva_student::count_len() {
    QFont font("Times", 14);
    QFontMetrics metrics(font);
    int name_w = metrics.boundingRect(QString::fromStdString(name)).width();
    int last_name_w = metrics.boundingRect(QString::fromStdString(last_name)).width();
    int age_w = metrics.boundingRect(QString::fromStdString(to_string(age))).width();
    int array_lens[5];
    array_lens[0] = max(name_w, metrics.boundingRect(QString::fromStdString("Имя")).width());
    array_lens[1] = max(last_name_w, metrics.boundingRect(QString::fromStdString("Фамилия")).width());
    array_lens[2] = max(age_w, metrics.boundingRect(QString::fromStdString("Возраст")).width());
    array_lens[3] = 0;
    array_lens[4] = 0;
    return array_lens;
}
