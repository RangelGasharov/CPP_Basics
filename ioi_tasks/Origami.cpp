#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findSmallestCombination(vector<vector<int>> &table, int longSide, int shortSide) {
    int smallestCombination{INT_MAX};
    int currentSum{INT_MAX};

    if (shortSide == longSide) {
        return -1;
    }
    if (shortSide == 1) {
        return longSide - 2;
    }

    for (int i = 0; i < shortSide / 2; i++) {
        int x = shortSide - 2 - i;
        currentSum = table[longSide - 1][i] + table[longSide - 1][x];
        if (currentSum < smallestCombination) {
            smallestCombination = currentSum;
        }
    }

    for (int i = 0; i < longSide / 2; i++) {
        int y = longSide - 2 - i;
        int n = table[i][shortSide - 1];
        int m = table[y][shortSide - 1];
        currentSum = n + m;
        if (currentSum < smallestCombination) {
            smallestCombination = currentSum;
        }
    }
    return smallestCombination;
}

void fillUpTable(vector<vector<int>> &table, int longSide, int shortSide) {
    for (int i = 0; i < longSide; i++) {
        for (int j = 0; j < shortSide && j <= i; j++) {
            int value{0};
            value = findSmallestCombination(table, i + 1, j + 1) + 1;
            table[i][j] = value;
            if (i < shortSide) {
                table[j][i] = value;
            }
        }
    }
}

void printTable(vector<vector<int>> table) {
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

int getMinimumAmountOfCuts(int a, int b) {
    if (a == 0 || b == 0 || a == b) { return 0; }
    if (a % b == 0) { return a / b - 1; }
    if (b % a == 0) { return b / a - 1; }
    if (a == 1) { return b - 1; }
    if (b == 1) { return a - 1; }

    int longSide, shortSide;
    if (a > b) {
        longSide = a;
        shortSide = b;
    } else {
        longSide = b;
        shortSide = a;
    }

    vector<vector<int>> dp(longSide, vector<int>(shortSide));
    fillUpTable(dp, longSide, shortSide);
    return dp[longSide - 1][shortSide - 1];
}

int main() {
    int a{0};
    int b{0};
    cin >> a >> b;
    cout << getMinimumAmountOfCuts(a, b) << endl;
    return 0;
}