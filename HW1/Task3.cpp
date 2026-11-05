#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double a;
    double b;
    cout << "¬ведите первую длину: ";
    cin >> a;
    cout << "¬ведите вторую длину: ";
    cin >> b;

    cout << "ƒлина первого больше второго: " << boolalpha << (a > b) << endl;
    cout << "ƒлина второго больше первого: " << boolalpha << (b > a) << endl;
    cout << "ƒлины обоих равны: " << boolalpha << (a == b) << endl;
}