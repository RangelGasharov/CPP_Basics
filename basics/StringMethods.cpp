#include <iostream>

using namespace std;

int main() {
    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    if (name.length() > 12) {
        std::cout << "Your name is over 12 characters.\n";
    } else if (name.empty()) {
        std::cout << "You did not enter your name.\n";
    } else {
        std::cout << "Welcome " << name << endl;
    };

    string userName = name.append("@gmail.com");
    std::cout << "Your username is now " << userName << endl;

    std::cout << "The first letter of your name is: " << name.at(0) << endl;

    name.insert(0, "@");
    std::cout << name << endl;
    name.erase(0,1);

    std::cout << name.find("a") << endl;

    name.erase(0, 2);
    std::cout << "Your first two letter were erased\n";
    std::cout << name << endl;

    name.clear();
    cout << "Name has been cleared" << endl;

    return 0;
}