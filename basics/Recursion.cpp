#include <iostream>
#include <cmath>

using namespace std;

int recursiveSum(int n) {
    if (n <= 1) {
        return n;
    } else {
        return n + recursiveSum(n - 1);
    }
}

int recursiveSumOfEvenSquares(int n) {
    if (n == 0) {
        return n;
    } else {
        return pow(2 * n, 2) + recursiveSumOfEvenSquares(n - 1);
    }
}

int recursiveSumOfOddSquares(int n) {
    if (n == 0) {
        return n;
    } else {
        return pow(2 * n - 1, 2) + recursiveSumOfOddSquares(n - 1);
    }
}

int main() {
    std::cout << "Sum: " << recursiveSum(3) << std::endl;
    std::cout << "Sum Even Squares: " << recursiveSumOfEvenSquares(4) << std::endl;
    std::cout << "Sum Odd Squares: " << recursiveSumOfOddSquares(4) << std::endl;
    return 0;
}