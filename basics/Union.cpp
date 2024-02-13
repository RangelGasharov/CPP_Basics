#include <iostream>

struct Vector2 {
    float x, y;
};

struct Vector4 {
    union {
        struct {
            float x, y, z, w;
        };
        struct {
            Vector2 a, b;
        };
    };
};

void PrintVector2(const Vector2 &vector) {
    std::cout << vector.x << ", " << vector.y << std::endl;
}

int main() {
    Vector4 vector4 = {1.0f, 2.0f, 3.0f, 4.0f};
    PrintVector2(vector4.a);
    PrintVector2(vector4.b);
    vector4.z = 500.0f;
    std::cout << "------" << std::endl;
    PrintVector2(vector4.a);
    PrintVector2(vector4.b);
    return 0;
}