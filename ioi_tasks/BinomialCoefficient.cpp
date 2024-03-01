#include <iostream>
#include <vector>

using namespace std;

// (n k) = n!/(k! * (n-k)!) = (n-1 k-1) + (n-1 k)

long long numberForModulo = 1000000007;
vector<vector<long long>> pascalsTriangle;

long long getBinomialCoefficientAndModulo(long long n, long long k)
{
    if (n == k || k == 0)
    {
        return 1;
    }

    if (pascalsTriangle[n][k] != -1)
    {
        return pascalsTriangle[n][k];
    }
    else
    {
        return pascalsTriangle[n][k] = (getBinomialCoefficientAndModulo(n - 1, k - 1) + getBinomialCoefficientAndModulo(n - 1, k)) % numberForModulo;
    }
}

int main()
{
    int n{0}, k{0};
    pascalsTriangle.reserve(5001);
    for (int i = 0; i < 5002; i++)
    {
        vector<long long> temp(5001, -1);
        pascalsTriangle.push_back(temp);
    }
    cin >> n;
    cin >> k;
    cout << getBinomialCoefficientAndModulo(n, k);
    return 0;
}