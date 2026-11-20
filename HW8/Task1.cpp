#include <iostream>
#include <algorithm>
#include <utility>
#include <cstddef>
using namespace std;

class IntArray {
private:
    size_t size_;
    int* data_;
public:
    // Параметризованный конструктор
    explicit IntArray(size_t n)
        : size_(n), data_(n ? new int[n]{} : nullptr) {}
    // Деструктор
    ~IntArray() {
        delete[] data_;
    }
    // Конструктор копирования
    IntArray(const IntArray& other)
        : IntArray(other.size_) {
        if (size_ > 0) {
            copy_n(other.data_, size_, data_);
        }
    }
    // Оператор копирующего присваивания
    IntArray& operator=(const IntArray& other) {
        if (this == &other) {
            return *this;
        }
        IntArray temp(other);
        swap(size_, temp.size_);
        swap(data_, temp.data_);
        return *this;
    }

    // Конструктор перемещения
    IntArray(IntArray&& other) noexcept
        : size_(other.size_), data_(other.data_) {
        other.size_ = 0;
        other.data_ = nullptr;
    }
    // Оператор перемещающего присваивания
    IntArray& operator=(IntArray&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        delete[] data_;
        size_ = other.size_;
        data_ = other.data_;
        other.size_ = 0;
        other.data_ = nullptr;
        return *this;
    }

    // Обычная индексация
    int& operator[](size_t index) {
        return data_[index];
    }
    // Индексация для const-объектов
    const int& operator[](size_t index) const {
        return data_[index];
    }
    // Получение размера
    size_t size() const {
        return size_;
    }
};

int main() {
    IntArray a(3);
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    cout << "a: ";
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    IntArray b = a;
    b[0] = 100;
    cout << "a after copy: " << a[0] << endl;
    cout << "b after change: " << b[0] << endl;
    IntArray c(1);
    c = a;
    cout << "c: " << c[0] << endl;
    c = c;
    IntArray d = std::move(a);
    cout << "d after move: ";
    for (size_t i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }
    cout << endl;
    cout << "a size after move: " << a.size() << endl;
    IntArray e(2);
    e = std::move(d);
    cout << "e size: " << e.size() << endl;
    return 0;
}
