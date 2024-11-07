#include "header.h"
#include "boost.h"
#include "tkacheva_group.h"

using namespace std;
BOOST_CLASS_EXPORT(tkacheva_headman)

using boost::archive::archive_flags;

// void tkacheva_group::add_student()
// {
//     shared_ptr<tkacheva_student> s = make_shared<tkacheva_student>();
//     s->tkacheva_student::create(cin);
//     students.push_back(s);
// }

// void tkacheva_group::add_headman()
// {
//     shared_ptr<tkacheva_headman> headman = make_shared<tkacheva_headman>();
//     headman->tkacheva_headman::create(cin);
//     students.push_back(headman);
// }

// void tkacheva_group::view_students()
// {
//     if (students.empty())
//     {
//         cout << "Данных о студентах нет." << endl;
//     }
//     else
//     {
//         for (auto& s : students) {
//             s->show(cout);
//         }
//     }
// }

// void tkacheva_group::delete_students()
// {
//     students.clear();
// }

// void tkacheva_group::save_data()
// {
//     if (students.empty())
//     {
//         cout << "Данных о студентах нет." << endl;
//         return;
//     }
//     string filename;
//     cout << "Введите название файла: ";
//     cin.ignore();
//     getline(cin, filename);
//     ofstream fout;
//     fout.open((filename), ios::trunc);
//     if (fout.is_open())
//     {
//         boost::archive::text_oarchive write(fout, archive_flags::no_header);
//         write << students;
//         cout << "Данные были записаны в файл." << endl;
//     }
//     else
//     {
//         cout << "Неверное имя файла." << endl;
//     }
//     fout.close();
// }

// void tkacheva_group::load_data()
// {
//     int count = 0;
//     ifstream fin;
//     string filename;
//     cout << "Введите название файла: ";
//     cin.ignore();
//     getline(cin, filename);
//     fin.open((filename), ios::in);
//     if (!fin.is_open())
//     {
//         cout << "Неверное название файла." << endl;
//     }
//     else
//     {
//         delete_students();
//         if (!fin) {
//             cout << "Невозможно считать данные из файла." << endl;
//             fin.close();
//             return;
//         }
//         else {
//             boost::archive::text_iarchive load(fin, archive_flags::no_header);
//             load >> students;
//             view_students();
//         }
//         fin.close();
//     }
// }

void tkacheva_group::count_max(int* array_max) {
    vector<vector<int>> matrix(students.size(), vector<int>(5));
    for (int i = 0; i < students.size(); i++){
        int* array_len = students[i]->count_len();
        for (int j = 0; j < 5; j++){
            matrix[i][j] = array_len[j];
        }
    }
    for (int j = 0; j < 5; j++) {
        int max_element = matrix[0][j];
        for (int i = 1; i < students.size(); i++) {
            if (matrix[i][j] > max_element) {
                max_element = matrix[i][j];
            }
        }
        array_max[j] = max_element;
    }
}

void tkacheva_group::draw(QPainter& painter, int* x, int* y, int* array_max) {
    for_each(students.begin(), students.end(), bind(&tkacheva_student::show_on_screen, placeholders::_1,ref(painter), x, y, array_max));
}

void tkacheva_group::load(const QString& path) {
    ifstream fin;
    fin.open(path.toStdWString(), ios::in);
    if (fin.is_open()) {
        if (fin.peek() != EOF) {
            boost::archive::text_iarchive load(fin, archive_flags::no_header);
            load >> students;
        }
        else {
        }
        fin.close();
    }
    else {
        cout << "файл не удалось открыть" << endl;
    }
}

void tkacheva_group::save(const QString& path) {
    std::ofstream out(path.toStdWString(), ios::trunc);
    boost::archive::text_oarchive ar(out, archive_flags::no_header);
    ar << students;
}
