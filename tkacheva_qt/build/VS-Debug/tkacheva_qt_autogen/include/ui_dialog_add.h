/********************************************************************************
** Form generated from reading UI file 'dialog_add.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ADD_H
#define UI_DIALOG_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_add
{
public:
    QFormLayout *formLayout_2;
    QCheckBox *checkBox_2;
    QFormLayout *formLayout;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog_add)
    {
        if (Dialog_add->objectName().isEmpty())
            Dialog_add->setObjectName("Dialog_add");
        Dialog_add->resize(400, 300);
        formLayout_2 = new QFormLayout(Dialog_add);
        formLayout_2->setObjectName("formLayout_2");
        checkBox_2 = new QCheckBox(Dialog_add);
        checkBox_2->setObjectName("checkBox_2");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, checkBox_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");

        formLayout_2->setLayout(1, QFormLayout::SpanningRole, formLayout);

        pushButton = new QPushButton(Dialog_add);
        pushButton->setObjectName("pushButton");

        formLayout_2->setWidget(2, QFormLayout::SpanningRole, pushButton);


        retranslateUi(Dialog_add);

        QMetaObject::connectSlotsByName(Dialog_add);
    } // setupUi

    void retranslateUi(QDialog *Dialog_add)
    {
        Dialog_add->setWindowTitle(QCoreApplication::translate("Dialog_add", "Dialog", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Dialog_add", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\320\260\321\200\320\276\321\201\321\202\321\203", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog_add", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_add: public Ui_Dialog_add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ADD_H
