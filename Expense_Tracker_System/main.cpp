#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Expense {
    string item;
    float amount;
};

void addExpense() {
    Expense e;
    ofstream out("expenses.txt", ios::app);

    cin.ignore(); // leftover newline
    cout << "Enter expense item: ";
    getline(cin, e.item);
    cout << "Enter amount: ";
    cin >> e.amount;

    out << e.item << "|" << e.amount << endl;
    out.close();

    cout << "Expense added successfully!" << endl;
}

void viewExpenses() {
    ifstream in("expenses.txt");
    if(!in) {
        cout << "No expenses found!" << endl;
        return;
    }
 string line;
    cout << "\n--- Expense List ---\n";
    float total = 0;
    while(getline(in, line)) {
        size_t pos = line.find("|");
        string item = line.substr(0, pos);
        float amount = stof(line.substr(pos+1));

        cout << "Item: " << item << ", Amount: " << amount << endl;
        total += amount;
    }
    cout << "Total Expense: " << total << endl;
    in.close();
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Expense\n2. View Expenses\n3. Exit\nChoose: ";
        cin >> choice;
        switch(choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: cout << "Exiting..."; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while(choice != 3);

    return 0;
}
