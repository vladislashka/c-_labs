#include <iostream>
#include <windows.h>
using namespace std;

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

void Divisors(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    int number;
    cout << "Введите число: ";
    cin >> number;
    cout << "Число Фибоначчи равно: "<< fibonacci(number) << endl;
    cout << "Факториал числа " << number << " равен: " << factorial(number) << endl;
    Divisors(number);
}
