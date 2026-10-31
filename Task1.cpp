#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

// Задание 1.1
int main1()
{
    setlocale(LC_ALL, "Russian");
    cout << "Булево: " << sizeof(bool) << " байт." << endl;
    cout << "Строка: " << sizeof(char) << " байт." << endl;
    cout << "Unsigned строка" << sizeof(unsigned char) << " байт." << endl;
    cout << "Целое число: " << sizeof(int) << " байт." << endl;
    cout << "Unsigned целое число: " << sizeof(unsigned int) << " байт." << endl;
    cout << "Short: " << sizeof(short) << " байт." << endl;
    cout << "Unsigned short: " << sizeof(unsigned short) << " байт." << endl;
    cout << "Long: " << sizeof(long) << " байт." << endl;
    cout << "Unsigned long" << sizeof(unsigned long) << " байт." << endl;
    cout << "Long long" << sizeof(long long) << " байт." << endl;
    cout << "Unsigned long long" << sizeof(unsigned long long) << " байт." << endl;
    cout << "Число типа float: " << sizeof(float) << " байт." << endl;
    cout << "Число типа double: " << sizeof(double) << " байт." << endl;
    return 0;
}

// Задание 1.2
int main2()
{
    unsigned char a = 255;
    cout << "До переполнения: " << int(a) << endl;
    a += 1;
    cout << "После переполнения: " << int(a) << endl;
    return 0;
}

// Задание 1.3
int main3()
{
    float a = 0.1;
    float b = 0.2;
    float c = 0.3;
    double d = a;
    double e = b;
    double f = c;
    cout << "FLOAT a + b = " << a + b << endl;
    cout << "DOUBLE a + b = " << d + e << endl;
    cout << "FLOAT a + b == c: " << boolalpha << (a + b == c) << endl;
    cout << "DOUBLE a + b == c: " << boolalpha << (d + e == f) << endl;
    return 0;
}

// Задание 1.4
int main()
{
    auto start = chrono::high_resolution_clock::now();
    this_thread::sleep_for(chrono::seconds(1));
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << main1() << endl;
    cout << main2() << endl;
    cout << main3() << endl;
    cout << "Время выполнения: " << duration.count() << " миллисекунд" << endl;
}
