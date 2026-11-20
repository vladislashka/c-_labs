#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;

// Шаблонный класс математического вектора
template<typename T>
class Vector {
public:
    vector<T> data;
    Vector(initializer_list<T> values) : data(values) {}
};

// 1. Сложение двух векторов
template<typename T>
Vector<T> operator+(const Vector<T>& a, const Vector<T>& b) {
    if (a.data.size() != b.data.size()) {
        throw invalid_argument("Different vector sizes");
    }
    Vector<T> result = a;
    for (size_t i = 0; i < a.data.size(); i++) {
        result.data[i] = a.data[i] + b.data[i];
    }
    return result;
}

// 2. Умножение вектора на скаляр
template<typename T>
Vector<T> operator*(const Vector<T>& v, T scalar) {
    Vector<T> result = v;

    for (T& x : result.data) {
        x *= scalar;
    }

    return result;
}

// Умножение скаляра на вектор
template<typename T>
Vector<T> operator*(T scalar, const Vector<T>& v) {
    return v * scalar;
}

// 3. Вывод вектора
template<typename T>
ostream& operator<<(ostream& out, const Vector<T>& v) {
    out << "(";
    for (size_t i = 0; i < v.data.size(); i++) {
        out << v.data[i];
        if (i + 1 < v.data.size()) {
            out << ", ";
        }
    }
    out << ")";
    return out;
}

// 4. Сравнение векторов
template<typename T>
bool operator==(const Vector<T>& a, const Vector<T>& b) {
    return a.data == b.data;
}

template<typename T>
bool operator!=(const Vector<T>& a, const Vector<T>& b) {
    return !(a == b);
}

// 5. Евклидова норма вектора
template<typename T>
double norm(const Vector<T>& v) {
    double sum = 0;
    for (const T& x : v.data) {
        double value = static_cast<double>(x);
        sum += value * value;
    }
    return sqrt(sum);
}

int main() {
    Vector<int> a = {1, 2, 3};
    Vector<int> b = {4, 5, 6};
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a * 3 = " << a * 3 << endl;
    cout << "3 * a = " << 3 * a << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "Norm(a) = " << norm(a) << endl;
    return 0;
}
