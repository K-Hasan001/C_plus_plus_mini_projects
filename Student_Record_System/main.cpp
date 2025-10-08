#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float marks;
};

void addStudent() {
    Student s;
    ofstream out("students.txt", ios::app);

    cout << "Enter Student ID: ";
    cin >> s.id;
    cin.ignore(); // leftover newline
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Marks: ";
    cin >> s.marks;

    out << s.id << "|" << s.name << "|" << s.marks << endl;
    out.close();
    cout << "Record Saved Successfully!" << endl;
}

void viewStudents() {
    ifstream in("students.txt");
    if(!in) {
        cout << "No records found!" << endl;
        return;
    }
string line;
    cout << "\n--- Student Records ---\n";
    while(getline(in, line)) {
        size_t pos1 = line.find("|");
        size_t pos2 = line.rfind("|");

        int id = stoi(line.substr(0, pos1));
        string name = line.substr(pos1+1, pos2-pos1-1);
        float marks = stof(line.substr(pos2+1));

        cout << "ID: " << id << ", Name: " << name << ", Marks: " << marks << endl;
    }
    in.close();
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Student\n2. View Students\n3. Exit\nChoose: ";
        cin >> choice;
        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: cout << "Exiting..."; break;
            default: cout << "Invalid choice!";
        }
    } while(choice != 3);

    return 0;
}
