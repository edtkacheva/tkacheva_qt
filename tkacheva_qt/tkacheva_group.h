#ifndef TKACHEVA_GROUP_H
#define TKACHEVA_GROUP_H
#include "boost.h"
#include "tkacheva_headman.h"

class tkacheva_group
{
private:
    friend class boost::serialization::access;
public:
    vector <shared_ptr<tkacheva_student>> students;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& students;
    }
    // void add_student();
    // void add_headman();
    // void view_students();
    // void delete_students();
    // void save_data();
    // void load_data();

    void count_max(int* array_max);
    void draw(QPainter& painter, int* x, int* y, int* array_max);
    void load(const QString& path);
    void save(const QString& path);
};
#endif
