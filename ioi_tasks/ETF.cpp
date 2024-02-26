#include <iostream>
#include <vector>

using namespace std;

double getBiggestProfit(vector<int> ETFs) {
    int currentRate;
    int currentDifference;
    int currentBiggestDifference{0};
    int currentLowestRate{ETFs[0]};

    cout << currentBiggestDifference << "\n";

    for (int i = 0; i < ETFs.size(); i++) {
        currentRate = ETFs[i];
        if (currentRate < currentLowestRate) {
            currentLowestRate = currentRate;
        }
        currentDifference = currentRate - currentLowestRate;
        if (currentDifference > currentBiggestDifference) {
            currentBiggestDifference = currentDifference;
        }
    }
    return currentBiggestDifference;
}

int main() {
    int amountOfETFs;
    cin >> amountOfETFs;

    vector<int> ETFs(amountOfETFs);
    for (int i = 0; i < ETFs.size(); i++) { cin >> ETFs[i]; }

    int biggestSum = getBiggestProfit(ETFs);
    cout << biggestSum << endl;
}


