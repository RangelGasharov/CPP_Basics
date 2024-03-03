#include <iostream>
#include <vector>

using namespace std;

long long countPartitions(int n) {
    vector<int> partitions(n + 1, 0);
    partitions[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            partitions[j] += partitions[j - i] % 1000000007;
            partitions[j] %= 1000000007;
        }
    }

    return partitions[n] % 1000000007;
}

int main() {
    int number{10};
    cin >> number;
    long long partitions = countPartitions(number);
    cout << partitions << endl;
    return 0;
}