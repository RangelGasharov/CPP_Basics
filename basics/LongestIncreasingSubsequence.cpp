#include <iostream>
#include <vector>

using namespace std;

int getLongestIncreasingSubsequence(vector<int> numbers) {
    vector<int> tails(numbers.size());
    int size = 0;
    for (int x: numbers) {
        int i = 0;
        int j = size;
        while (i != j) {
            int m = (i + j) / 2;
            if (tails[m] < x) {
                i = m + 1;
            } else {
                j = m;
            }
        }
        tails[i] = x;
        if (i == size) {
            ++size;
        }
    }
    return size;
}

int main() {
    vector<int> numbers = {1, 2, 8, 3, 9, 4};
    cout << getLongestIncreasingSubsequence(numbers) << std::endl;
    return 0;
}