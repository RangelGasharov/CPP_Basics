#include <iostream>

using namespace std;

void move(int start, int end) {
    cout << start << " " << end << endl;
}

int hanoi2(int n, int start, int temp, int end) {
    if (n == 1) { move(start, end); }
    hanoi2(n - 1, start, temp, end);
    move(start, end);
    hanoi2(n - 1, start, temp, end);
}

int hanoi(int n) {
    hanoi2(n, 1, 3, 2);
}

int main() {
    hanoi(3);
}
