#include <iostream>

using namespace std;

class Car {
private:
    string brand;
    int maxSpeed;
    int price;
public:

    Car(string aBrand, int aMaxSpeed, int aPrice) {
        setBrand(aBrand);
        setMaxSpeed(aMaxSpeed);
        setPrice(aPrice);
    }

    void setBrand(string aBrand) {
        brand = aBrand;
    }

    void setMaxSpeed(int aMaxSpeed) {
        maxSpeed = aMaxSpeed;
    }

    void setPrice(int aPrice) {
        price = aPrice;
    }

    string getBrand() {
        return brand;
    }

    int getMaxSpeed() {
        return maxSpeed;
    }

    int getPrice() {
        return price;
    }
};

class RacingCar : public Car {
public:
    using Car::Car;

    void turnOnTurboMode() {
        cout << "Turbo Mode is on." << endl;
    }
};

int main() {
    Car mercedes("Mercedes", 250, 20000);
    cout << mercedes.getPrice() << endl;
    RacingCar porsche("Porsche", 330, 75000);
    cout << porsche.getPrice() << endl;
    cout << porsche.getMaxSpeed() << endl;
    porsche.turnOnTurboMode();
    return 0;
}
