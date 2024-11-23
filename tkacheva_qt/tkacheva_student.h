#pragma once

#include "header.h"
#include "boost.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QDialog>

using namespace std;

class Dialog;
class tkacheva_student
{
private:
    friend class boost::serialization::access;
public:
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    string name = "";
    string last_name = "";
    int age = 0;
    virtual void create(istream& in);
    virtual void show(ostream& out);
    virtual void show_on_screen(QPainter& painter,int* x, int* y, int* array_lens);
    virtual int* count_len();
    virtual void drawLabels(QDialog *dialog, QFormLayout* layout, bool readOnly);
    virtual void add();
    tkacheva_student() {}
    virtual ~tkacheva_student() {}
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& name;
        ar& last_name;
        ar& age;
    }
};
