#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int id;
    string name;
    float marks;
};

int main() {
    Student s;
    ofstream out("students.txt", ios::app);

    cout << "Enter Student ID: ";
    cin >> s.id;
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter Marks: ";
    cin >> s.marks;

    out << s.id << " " << s.name << " " << s.marks << endl;
    out.close();

    cout << "Record Saved Successfully!" << endl;
    return 0;
}
