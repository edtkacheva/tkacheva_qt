#pragma once
#include "tkacheva_student.h"
#include "boost.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QScrollArea>
#include <QVBoxLayout>

class tkacheva_headman : public tkacheva_student
{
    friend class boost::serialization::access;
public:
    QLineEdit *lineEdit4;
    QLineEdit *lineEdit5;
    string group_name = "";
    string email = "";
    BOOST_SERIALIZATION_SPLIT_MEMBER()
    tkacheva_headman() {}
    ~tkacheva_headman() override {}
    void create(istream& in) override;
    void show(ostream& out) override;
    void show_on_screen(QPainter& painter,int* x, int* y, int* array_lens) override;
    int* count_len() override;
    void drawLabels(QDialog *dialog, QFormLayout* layout, bool readOnly) override;
    void add() override;
    template<class Archive>
    void save(Archive& ar, const unsigned int version) const
    {
        ar& boost::serialization::base_object<tkacheva_student>(*this);
        ar << group_name;
        ar << email;
    }
    template<class Archive>
    void load(Archive& ar, const unsigned int version)
    {
        ar >> boost::serialization::base_object<tkacheva_student>(*this);
        ar >> group_name;
        ar >> email;
    }
};
