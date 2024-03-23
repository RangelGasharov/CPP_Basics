#include <iostream>
#include <vector>
#include <array>

using namespace std;

struct Item {
    int weight;
    int value;
};

vector<Item> allItems;

int main() {
    int maxWeight{10}, amountOfItems{10}, itemWeight{10}, itemValue{10};
    cin >> maxWeight >> amountOfItems;

    int table[amountOfItems + 1][maxWeight + 1] = {};

    for (int i = 0; i < amountOfItems; i++) {
        cin >> itemWeight >> itemValue;
        allItems.push_back({itemWeight, itemValue});
    }

    for (int i = 0; i < amountOfItems + 1; i++) {
        table[i][0] = 0;
    }

    for (int i = 0; i < maxWeight + 1; i++) {
        table[0][i] = 0;
    }

    for (int item = 1; item <= amountOfItems; item++) {
        for (int capacity = 1; capacity <= maxWeight; capacity++) {
            int maxValueWithoutCurrent = table[item - 1][capacity];
            int maxValueWithCurrent{0};

            int weightOfCurrent = allItems[item - 1].weight;
            if (capacity >= weightOfCurrent) {
                maxValueWithCurrent = allItems[item - 1].value;
                table[item][capacity] = maxValueWithCurrent;
                int remainingCapacity = capacity - weightOfCurrent;
                maxValueWithCurrent += table[item - 1][remainingCapacity];
            }

            table[item][capacity] = max(maxValueWithoutCurrent, maxValueWithCurrent);
        }
    }

    cout << table[amountOfItems][maxWeight] << endl;

    return 0;
}
