#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int age, stock;
    double sum, discount = 0;
    bool promo, blocked, marked;
    cout << "Введите свой возраст: ";
    cin >> age;
    cout << "Сумма корзины: ";
    cin >> sum;
    cout << "Есть ли у вас промокод? (1 - да, 0 нет) ";
    cin >> promo;
    cout << "Заблокирован ли аккаунт? (1 - да, 0 - нет) ";
    cin >> blocked;
    cout << "Является ли товар маркированным? (1 - да, 0 - нет ) ";
    cin >> marked;
    cout << "Сколько осталось товара? ";
    cin >> stock;
    if (blocked)
    {
        cout << "Операция отклонена по причине \"blocked account\".";
    }
    if (age < 18 && marked)
    {
        cout << "В оформлении отказано.";
    }
    if (stock <= 0)
    {
        cout << "Отмена оформления, отсутствуют позиции на складе.";
    }
    if (sum >= 10000)
    {
        discount = 15;
    }
    else if (sum >= 5000 && promo)
    {
        discount = 10;
    }
    double total = sum * (1 - discount / 100);

    cout << "Ваш заказ оформлен!" << endl;
    cout << "Ваша скидка составила " << discount << "%." << endl;
    cout << "Итоговая сумма: " << total << " руб." << endl;
}