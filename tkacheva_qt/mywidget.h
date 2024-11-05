#ifndef MYWIDGET_H
#define MYWIDGET_H
#include "boost.h"
#include "tkacheva_group.h"

class MyWidget : public QWidget
{
    friend class boost::serialization::access;
    Q_OBJECT
public:
    tkacheva_group group;
    explicit MyWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void load(const QString& path);
    void save(const QString& path);
    void clean();
    void onSetWidth(int);
    void onSetHeight(int);
signals:
};

#endif // MYWIDGET_H
