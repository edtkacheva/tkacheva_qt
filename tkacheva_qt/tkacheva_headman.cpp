#include "tkacheva_headman.h"
#include "dialog.h"

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
    int dx = 5;
    painter.drawText(*x, *y, QString::fromLocal8Bit(name));
    *(x) += array_lens[0] + 2 * dx;
    painter.drawText(*x, *y, QString::fromLocal8Bit(last_name));
    *(x) += array_lens[1] + 2 * dx;
    painter.drawText(*x, *y, QString::fromLocal8Bit(to_string(age)));
    *(x) += array_lens[2] + 2 * dx;
    painter.drawText(*x, *y, QString::fromLocal8Bit(group_name));
    *(x) += array_lens[3] + 2 * dx;
    painter.drawText(*x, *y, QString::fromLocal8Bit(email));
    *(y) += metrics.height() + 10;
}

int* tkacheva_headman::count_len() {
    QFont font("Times", 14);
    QFontMetrics metrics(font);
    int name_w = metrics.boundingRect(QString::fromLocal8Bit(name)).width();
    int last_name_w = metrics.boundingRect(QString::fromLocal8Bit(last_name)).width();
    int age_w = metrics.boundingRect(QString::fromLocal8Bit(to_string(age))).width();
    int group_name_w = metrics.boundingRect(QString::fromLocal8Bit(group_name)).width();
    int email_w = metrics.boundingRect(QString::fromLocal8Bit(email)).width();
    int array_lens[5];
    array_lens[0] = max(name_w, metrics.boundingRect(QString::fromStdString("Имя")).width());
    array_lens[1] = max(last_name_w, metrics.boundingRect(QString::fromStdString("Фамилия")).width());
    array_lens[2] = max(age_w, metrics.boundingRect(QString::fromStdString("Возраст")).width());
    array_lens[3] = max(group_name_w, metrics.boundingRect(QString::fromStdString("Группа")).width());
    array_lens[4] = max(email_w, metrics.boundingRect(QString::fromStdString("Почта")).width());
    return array_lens;
}

void tkacheva_headman::drawLabels(QDialog *dialog, QFormLayout* layout, bool readOnly) {
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

    QLabel *label4 = new QLabel("Группа: ", dialog);
    lineEdit4 = new QLineEdit(dialog);
    lineEdit4->setText(QString::fromLocal8Bit(group_name));
    lineEdit4->setReadOnly(readOnly);

    QLabel *label5 = new QLabel("Почта: ", dialog);
    lineEdit5 =new QLineEdit(dialog);
    lineEdit5->setText(QString::fromLocal8Bit(email));
    lineEdit5->setReadOnly(readOnly);

    layout->addRow(label1, lineEdit1);
    layout->addRow(label2, lineEdit2);
    layout->addRow(label3, lineEdit3);
    layout->addRow(label4, lineEdit4);
    layout->addRow(label5, lineEdit5);

}

void tkacheva_headman::add() {
    name = lineEdit1->text().toLocal8Bit().toStdString();
    last_name = lineEdit2->text().toLocal8Bit().toStdString();
    age = lineEdit3->text().toInt();
    group_name = lineEdit4->text().toLocal8Bit().toStdString();
    email = lineEdit5->text().toLocal8Bit().toStdString();
}
