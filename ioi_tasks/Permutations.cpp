#include <vector>
#include <iostream>

using namespace std;

void permutations_2(int currentIndex, int end, vector<int> &permutationsVector) {
    if (currentIndex == end) {
        for (int i = 0; i <= end; i++) {
            cout << permutationsVector[i] << " ";
        }
        cout << "\n";
    } else {
        for (int i = currentIndex; i <= end; i++) {
            swap(permutationsVector[currentIndex], permutationsVector[i]);
            permutations_2(currentIndex + 1, end, permutationsVector);
            swap(permutationsVector[i], permutationsVector[currentIndex]);
        }
    }
}

void permutations(int n) {
    vector<int> permutationsVector;
    for (int i = 0; i < n; i++) {
        permutationsVector.push_back(i + 1);
    }
    permutations_2(0, n - 1, permutationsVector);
}

int main() {
    int n{1};
    cin >> n;
    permutations(n);
    return 0;
}