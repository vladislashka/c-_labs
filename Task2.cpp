#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string name;
    int birth_day;
    int birth_month;
    int birth_year;
    cout << "Введите ваше имя: ";
    cin >> name;
    cout << "Введите день вашего рождения: ";
    cin >> birth_day;
    cout << "Введите месяц вашего рождения: ";
    cin >> birth_month;
    cout << "Введите год вашего рождения: ";
    cin >> birth_year;
    // Вычисляем текущий возраст
    int age = 2026 - birth_year - (birth_month > 10 || birth_month == 10 && birth_day > 31);

    cout << "Пользователю с именем " << name << " на данный момент " << age << " лет.";
    return 0;
}
