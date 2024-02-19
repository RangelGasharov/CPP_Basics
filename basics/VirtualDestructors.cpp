#include <iostream>
#include <string>

void printEntity();

class Entity {
public:
    int x, y;

    Entity(int x, int y) {
        this->x = x;
        this->y = y;

        Entity &e = *this;
        printEntity(*this);
    }

    int getX() const {
        const Entity &e = *this;
    }
};

void printEntity(const Entity &e);

int main() {
    return 0;
}
