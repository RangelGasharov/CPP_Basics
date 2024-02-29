#include <iostream>

using namespace std;

const long long mod = 1000000007;

long long fibonacci_mod(long long n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    long long a = 0, b = 1;
    for (long long i = 2; i <= n; i++) {
        long long c = (a + b) % mod;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    long long n;
    cin >> n;
    cout << fibonacci_mod(n) << endl;
    return 0;
}