#include <iostream>

void bakePizza();

void bakePizza(std::string topping1);

void bakePizza(std::string topping1, std::string topping2);


int main() {
    bakePizza();
    bakePizza("red peppers");
    bakePizza("mozzarella", "mushrooms");
    return 0;
}

void bakePizza() {
    std::cout << "Here is your pizza!" << std::endl;
}

void bakePizza(std::string topping1) {
    std::cout << "Here is your pizza with " << topping1 << "!" << std::endl;
}

void bakePizza(std::string topping1, std::string topping2) {
    std::cout << "Here is your pizza with " << topping1 << " and " << topping2 << "!" << std::endl;
}