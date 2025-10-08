#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string item;
    float amount;
    ofstream file("expenses.txt", ios::app);

    cout << "Enter expense item: ";
    cin >> item;
    cout << "Enter amount: ";
    cin >> amount;

    file << item << " " << amount << endl;
    file.close();

    cout << "Expense added successfully!" << endl;
}
