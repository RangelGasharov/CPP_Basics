#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int amountOfCuts{0};

int findSmallestCombination(vector<vector<int>> table, int a, int b) {
    /* int a = table[0].size();
     int b = table.size();*/
    int smallestCombination{INT_MAX};
    int currentSum{INT_MAX};

    if (a == b) {
        return 0;
    }
    if (a == 1) {
        return b - 1;
    }
    if (b == 1) {
        return a - 1;
    }

    for (int i = 0; i <= a / 2; i++) {
        int x = a - 2 - i;
        currentSum = table[b - 1][i] + table[b - 1][x];
        if (currentSum < smallestCombination) {
            smallestCombination = currentSum;
        }
    }

    for (int i = 0; i <= b / 2; i++) {
        int y = b - 2 - i;
        int n = table[i][a - 1];
        int m = table[y][a - 1];
        currentSum = n + m;
        if (currentSum < smallestCombination) {
            smallestCombination = currentSum;
        }
    }
    return smallestCombination;
}

void fillUpTable(vector<vector<int>> &table) {
    int longSide, shortSide;
    if (table.size() > table[0].size()) {
        longSide = table.size();
        shortSide = table[0].size();
    } else {
        shortSide = table.size();
        longSide = table[0].size();
    }
    for (int i = 0; i < longSide; i++) {
        for (int j = 0; j < shortSide; j++) {
            int value{0};
            if (i == j) {
                value = 0;
            }
            value = findSmallestCombination(table, i + 1, j + 1) + 1;
            table[i][j] = value;
            table[j][i] = value;
        }
        std::cout << std::endl;
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

    vector<vector<int>> dp(b, vector<int>(a));
    fillUpTable(dp);
    printTable(dp);

    return dp[a - 1][b - 1];
}

int main() {
    int a{0};
    int b{0};
    cin >> a >> b;
    //  cout << getMinimumAmountOfCuts(a, b) << endl;
    cout << findSmallestCombination({{1, 2, 3},
                                     {2, 0, 1},
                                     {1, 3, 0},
                                     {5, 4, 3}}, 3, 4);
    return 0;
}