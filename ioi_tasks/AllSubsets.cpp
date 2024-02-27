#include <vector>
#include <iostream>

using namespace std;

void printSubSets(int n, vector<int> vector) {
    if (n == 0) {
        for (int x: vector) {
            cout << x << " ";
        }
        cout << "\n";
        return;
    }

    printSubSets(n - 1, vector);
    vector.push_back(n);
    printSubSets(n - 1, vector);
    vector.pop_back();
}

int main() {
    int n{0};
    cin >> n;
    printSubSets(n, {});
    return 0;
}
