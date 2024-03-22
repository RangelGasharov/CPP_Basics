#include <iostream>

using namespace std;

int amountOfCuts{0};

int getMinimumAmountOfCuts(int a, int b) {
    if (a == 0 || b == 0 || a == b) { return 0; }

    if (a % b == 0) { return a / b - 1; }

    if (b % a == 0) { return b / a - 1; }

    if (a == 1) { return b - 1; }

    if (b == 1) { return a - 1; }

    if (a > b) { amountOfCuts += getMinimumAmountOfCuts(a - b, b % a) + 1; }

    if (b > a) { amountOfCuts += getMinimumAmountOfCuts(b - a, a % b) + 1; }

    return amountOfCuts;
}

int main() {
    int a{7};
    int b{8};
    cin >> a >> b;
    cout << getMinimumAmountOfCuts(a, b);
    return 0;
}