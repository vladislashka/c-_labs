#include <iostream>
#include <windows.h>
using namespace std;

bool isLeapYear(int n) {
    if (n % 400 == 0) {
        return true;
    }
    else if (n % 4 == 0 && n % 100 != 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    int year;
    cout << "Введите год: ";
    cin >> year;
    if (isLeapYear(year)) {
        cout << year << " год является високосным.";
    }
    else {
        cout << year << " год не является високосным.";
    }
}
