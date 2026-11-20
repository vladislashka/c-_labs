#include <iostream>
#include <string>
using namespace std;

// Абстрактный базовый класс
class Transport {
public:
    virtual void move() const = 0;
    virtual ~Transport() = default;
};

// Первый производный класс
class Car : public Transport {
private:
    string brand;
public:
    Car(const string& b) : brand(b) {}
    void move() const override {
        cout << "Car " << brand
             << " is driving on the road" << endl;
    }
};

// Второй производный класс
class Bicycle : public Transport {
private:
    int gears;
public:
    Bicycle(int g) : gears(g) {}
    void move() const override {
        cout << "Bicycle with " << gears
             << " gears is moving" << endl;
    }
};

// Третий производный класс
class Airplane : public Transport {
private:
    int maxAltitude;
public:
    Airplane(int altitude) : maxAltitude(altitude) {}
    void move() const override {
        cout << "Airplane is flying at up to "
             << maxAltitude << " meters" << endl;
    }
};

void showMovement(const Transport& transport) {
    transport.move();
}

int main() {
    Car car("Toyota");
    Bicycle bicycle(21);
    Airplane airplane(12000);
    showMovement(car);
    showMovement(bicycle);
    showMovement(airplane);
    return 0;
}
