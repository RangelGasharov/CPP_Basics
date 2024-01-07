#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Preference {
    int a, b, c, d;
};

struct Position {
    int r, c;
};

struct Coordinates {
    int num, p1, p2;
    bool isTaken;
};

bool compareByP2(const Coordinates &a, const Coordinates &b) {
    return a.p2 < b.p2;
}

std::vector<Position> solve(const std::vector<Preference> &preference) {
    const int n = preference.size();

    vector<Coordinates> xCoordinates(n);
    vector<Coordinates> yCoordinates(n);
    vector<Coordinates> xCoordinatesPossibleSolutions;
    vector<Coordinates> yCoordinatesPossibleSolutions;
    vector<int> xCoordinatesResults;
    vector<int> yCoordinatesResults;
    vector<Position> emptyVector;


    for (int i = 0; i < n; i++) {
        xCoordinates[i].num = i + 1;
        xCoordinates[i].p1 = preference[i].a;
        xCoordinates[i].p2 = preference[i].c;
        xCoordinates[i].isTaken = false;

        yCoordinates[i].num = i + 1;
        yCoordinates[i].p1 = preference[i].b;
        yCoordinates[i].p2 = preference[i].d;
        yCoordinates[i].isTaken = false;
    }

    for (int j = 1; j <= n; j++) {

        for (int i = 0; i < n; i++) {
            if ((xCoordinates[i].p2 < j) || (xCoordinates[i].p1 > j)) { continue; }
            if (xCoordinates[i].isTaken == 1) { continue; }
            xCoordinatesPossibleSolutions.push_back(xCoordinates[i]);
        }

        for (int i = 0; i < n; i++) {
            if ((yCoordinates[i].p2 < j) || (yCoordinates[i].p1 > j)) { continue; }
            if (yCoordinates[i].isTaken == 1) { continue; }
            yCoordinatesPossibleSolutions.push_back(yCoordinates[i]);
        }

        std::sort(xCoordinatesPossibleSolutions.begin(), xCoordinatesPossibleSolutions.end(), compareByP2);
        std::sort(yCoordinatesPossibleSolutions.begin(), yCoordinatesPossibleSolutions.end(), compareByP2);

        for (int i = 0; i < xCoordinatesPossibleSolutions.size() - 1; i++) {
            if ((xCoordinatesPossibleSolutions[i].p2 == xCoordinatesPossibleSolutions[i + 1].p2) &&
                xCoordinatesPossibleSolutions[i].p2 - j == 0) {
                return emptyVector;
            }
        }

        for (int i = 0; i < yCoordinatesPossibleSolutions.size() - 1; i++) {
            if ((yCoordinatesPossibleSolutions[i].p2 == yCoordinatesPossibleSolutions[i + 1].p2) &&
                yCoordinatesPossibleSolutions[i].p2 - j == 0) {
                return emptyVector;
            }
        }

        xCoordinatesResults.push_back(xCoordinatesPossibleSolutions[0].num);
        yCoordinatesResults.push_back(yCoordinatesPossibleSolutions[0].num);

        for (int i = 0; i < n; i++) {
            if (xCoordinates[i].num == xCoordinatesPossibleSolutions[0].num) {
                xCoordinates[i].isTaken = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (yCoordinates[i].num == yCoordinatesPossibleSolutions[0].num) {
                yCoordinates[i].isTaken = true;
            }
        }

        xCoordinatesPossibleSolutions.clear();
        yCoordinatesPossibleSolutions.clear();
    }

    vector<int> xCoordinatesResultsInverted(xCoordinatesResults.size());
    vector<int> yCoordinatesResultsInverted(yCoordinatesResults.size());

    for (int i = 0; i < xCoordinatesResults.size(); i++) {
        int numberValue = xCoordinatesResults[i];
        std::cout << i << ": " << numberValue << std::endl;
        xCoordinatesResultsInverted[numberValue - 1] = i + 1;
    }

    for (int i = 0; i < yCoordinatesResults.size(); i++) {
        int numberValue = yCoordinatesResults[i];
        std::cout << i << ": " << numberValue << std::endl;
        yCoordinatesResultsInverted[numberValue - 1] = i + 1;
    }

    vector<Position> res(n);
    for (int i = 0; i < res.size(); i++) {
        res[i] = {xCoordinatesResultsInverted[i], yCoordinatesResultsInverted[i]};
    }

    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<Preference> preferences(n);
    for (Preference &p: preferences)
        scanf("%d %d %d %d", &p.a, &p.b, &p.c, &p.d);

    const vector<Position> result = solve(preferences);
    if (result.empty())
        printf("-1\n");
    else
        for (int i = 0; i < n; i++)
            printf("%d %d\n", result[i].r, result[i].c);
    return 0;
}

/*
4
1 1 1 1
1 3 2 4
3 1 4 2
2 2 4 4


10
1 1 2 2
3 2 3 2
2 3 4 4
3 5 5 8
4 8 8 10
6 5 6 7
7 1 10 4
8 6 8 6
9 9 10 10
9 2 10 8


11
1 1 1 1
1 1 2 2
3 2 3 2
2 3 4 4
3 5 5 8
4 8 8 10
6 5 6 7
7 1 10 4
8 6 8 6
9 9 10 10
9 2 10 8
 */

