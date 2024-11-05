#pragma once
#include "boost.h"

using namespace std;

template <typename T>
void getcorrectnumber(T& x) {
    cin >> x;
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "������ �����! ��������� �������." << endl;
        cin >> x;
    }
}

static void printmenu() {
    cout << "1. �������� ��������." << endl
         << "2. �������� ��������." << endl
         << "3. ������� ���� ���������." << endl
         << "4. ������� ���� ���������." << endl
         << "5. ��������� ������ � ����." << endl
         << "6. ������� ������ �� �����." << endl
         << "0. �����." << endl
         << "----------------------------" << endl;
}
