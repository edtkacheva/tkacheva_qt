#include "tkacheva_student.h"
#include "header.h"
#include "boost.h"
#include "dialog.h"

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
    int dx = 5;
    painter.drawText(*x, *y, QString::fromLocal8Bit(name));
    *(x) += array_lens[0] + 2 * dx;
    painter.drawText(*x, *y, QString::fromLocal8Bit(last_name));
    *(x) += array_lens[1] + 2 * dx;
    painter.drawText(*x, *y, QString::fromLocal8Bit(to_string(age)));
    *(y) += metrics.height() + 10;
}

int* tkacheva_student::count_len() {
    QFont font("Times", 14);
    QFontMetrics metrics(font);
    int name_w = metrics.boundingRect(QString::fromLocal8Bit(name)).width();
    int last_name_w = metrics.boundingRect(QString::fromLocal8Bit(last_name)).width();
    int age_w = metrics.boundingRect(QString::fromLocal8Bit(to_string(age))).width();
    int array_lens[5];
    array_lens[0] = max(name_w, metrics.boundingRect(QString::fromStdString("Имя")).width());
    array_lens[1] = max(last_name_w, metrics.boundingRect(QString::fromStdString("Фамилия")).width());
    array_lens[2] = max(age_w, metrics.boundingRect(QString::fromStdString("Возраст")).width());
    array_lens[3] = metrics.boundingRect(QString::fromStdString("Группа")).width();
    array_lens[4] = metrics.boundingRect(QString::fromStdString("Почта")).width();
    return array_lens;
}

void tkacheva_student::drawLabels(QDialog *dialog, QFormLayout* layout, bool readOnly) {
    QLabel *label1 = new QLabel("Имя: ", dialog);
    lineEdit1 = new QLineEdit(dialog);
    lineEdit1->setText(QString::fromLocal8Bit(name));
    lineEdit1->setReadOnly(readOnly);

    QLabel *label2 = new QLabel("Фамилия: ", dialog);
    lineEdit2 =new QLineEdit(dialog);
    lineEdit2->setText(QString::fromLocal8Bit(last_name));
    lineEdit2->setReadOnly(readOnly);

    QLabel *label3 = new QLabel("Возраст: ", dialog);
    lineEdit3 = new QLineEdit(dialog);
    lineEdit3->setText(QString::number(age));
    lineEdit3->setReadOnly(readOnly);

    layout->addRow(label1, lineEdit1);
    layout->addRow(label2, lineEdit2);
    layout->addRow(label3, lineEdit3);
}

void tkacheva_student::add() {
    name = lineEdit1->text().toLocal8Bit().toStdString();
    last_name = lineEdit2->text().toLocal8Bit().toStdString();
    age = lineEdit3->text().toInt();
}
