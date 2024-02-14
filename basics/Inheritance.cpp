#include <iostream>

using namespace std;

class MenuItem {
public:
    string name;
    double calories;

    void print() {
        cout << name << " [" << calories << "] " << endl;
    }
};

class Drink : public MenuItem {
public:
    double ounces;

    double caloriesPerOunce() {
        return calories / ounces;
    }
};

int main() {
    MenuItem hamburger;
    hamburger.name = "Hamburger";
    hamburger.calories = 500;
    hamburger.print();

    Drink milkshake;
    milkshake.name = "Milkshake";
    milkshake.calories = 200;
    milkshake.ounces = 5;
    milkshake.print();
    cout << "calories per ounce: " << milkshake.caloriesPerOunce() << endl;

    MenuItem *ptr;
    ptr = &milkshake;
    ptr->print();
}