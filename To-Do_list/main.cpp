#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int choice;
    string task;

    cout << "1. Add Task\n2. View Tasks\nChoose: ";
    cin >> choice;

    if(choice == 1) {
        ofstream file("todo.txt", ios::app);
        cout << "Enter task: ";
        cin.ignore();
        getline(cin, task);
        file << "- " << task << endl;
        file.close();
        cout << "Task added!" << endl;
    } else if(choice == 2) {
        ifstream file("todo.txt");
        cout << "Your To-Do List:\n";
        while(getline(file, task)) cout << task << endl;
        file.close();
    } else {
        cout << "Invalid choice!";
    }
}
