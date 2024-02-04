#include <iostream>
#include <cstring>

using namespace std;

#define LOG(x) std::cout << x << std::endl;

int main() {
    int variable = 8;
    int *ptr = &variable;
    *ptr = 10;
    LOG(variable);
    LOG(ptr);

    char* buffer = new char[8];
    memset(buffer, 0, 8);

    char** ptr2 = &buffer;

    delete[] buffer;
    LOG(ptr2);
    return 0;
}