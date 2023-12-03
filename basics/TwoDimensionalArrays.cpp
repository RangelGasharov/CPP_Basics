#include <iostream>

using namespace std;

int main() {
    int numberGrid[4][2] = {
            {1, 4},
            {2, 7},
            {9, 4},
            {5, 3}
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            cout << numberGrid[i][j];
        }
        cout << endl;
    }
}
