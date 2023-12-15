#include <iostream>

using namespace std;

int main() {
    double temperature;
    char unit;

    std::cout << "Temperature conversion\n";
    std::cout << "F = Fahrenheit \n";
    std::cout << "C = Celsius \n";
    std::cout << "Please write down the unit you would like to convert to:";
    std::cin >> unit;

    if (unit == 'F' || unit == 'f') {
        std::cout << "Please enter the temperature in Celsius: ";
        std::cin >> temperature;

        temperature = (temperature * 1.8) + 32.0;
        std::cout << "Temperature is: " << temperature << "F\n";
    } else if (unit == 'C' || unit == 'c') {
        std::cout << "Please enter the temperature in Fahrenheit: ";
        std::cin >> temperature;

        temperature = (temperature - 32.0) / 1.8;
        std::cout << "Temperature is: " << temperature << "C\n";
    } else {
        std::cout << "Please enter in only C or F\n";
    }

    return 0;
}
