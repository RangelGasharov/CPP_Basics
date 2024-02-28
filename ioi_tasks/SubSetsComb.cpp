#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getAllSubSets(int n, int k) {
    vector<vector<int>> subSets;
    vector<int> numbers;
    vector<int> temp;
    for (int i = 0; i < n; i++) { numbers.push_back(i + 1); }

    for (int i = 0; i < n - k + 1; i++) {

    }


    /*for (int i = 0; i < n - k + 1; i++) {
        for (int j = i + k; j > i; j--) {
            for (int l = i; l < j; l++) {
                cout << numbers[l];
            }
            cout << endl;
        }
    }*/
    if (k > 1) {
        getAllSubSets(n - 1, k - 1);
    } else {
        return subSets;
    }
}

int main() {
    getAllSubSets(6, 3);
    return 0;
}