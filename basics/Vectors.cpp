#include <iostream>
#include <vector>

void print_data(std::vector<int> &data) {
    data.push_back(10);
    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i] << "\t";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {10, 45, 127, 980};
    data.push_back(1200);
    std::cout << data[data.size() - 1] << std::endl;
    data.pop_back();
    std::cout << data[data.size() - 1] << std::endl;
    std::cout << "------" << std::endl;
    print_data(data);
    print_data(data);
    print_data(data);
}

