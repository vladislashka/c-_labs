#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double a;
    double b;
    cout << "Введите первую длину: ";
    cin >> a;
    cout << "Введите вторую длину: ";
    cin >> b;

    cout << "Длина первого больше второго: " << boolalpha << (a > b) << endl;
    cout << "Длина второго больше первого: " << boolalpha << (b > a) << endl;
    cout << "Длины обоих равны: " << boolalpha << (a == b) << endl;
}
