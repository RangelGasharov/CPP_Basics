#include <iostream>
#include <string>
#include <tuple>

struct Person{
    std::string Name;
    int Age;
};

std::tuple<std::string, int> CreatePerson() {
    return {"Bill", 24};
};

int main() {
    auto[name, age] = CreatePerson();
    std::cout << name;
    return 0;
}