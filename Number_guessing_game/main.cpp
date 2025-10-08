#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int num = rand() % 100 + 1;
    int guess, tries = 0;

    cout << "Guess the number (1-100): ";
    do {
        cin >> guess;
        tries++;
        if (guess > num) cout << "Too high! Try again: ";
        else if (guess < num) cout << "Too low! Try again: ";
        else cout << "Correct! You guessed it in " << tries << " tries.\n";
    } while (guess != num);
}
