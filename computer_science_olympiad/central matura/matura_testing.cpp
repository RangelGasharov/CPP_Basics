#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

struct Preference {
    int a, b, c, d;
};

struct Position {
    int r, c;
};

std::vector<Position> solve(const std::vector<Preference> &preference) {
    const int n = preference.size();

    struct Coordinates {
        int num, p1, p2;
        bool isTaken;
    };

    vector<Coordinates> xCoordinates(n);
    vector<Coordinates> yCoordinates(n);
    vector<int> xCoordinatesResults(n);
    vector<int> yCoordinatesResults(n);

    for (int i = 0; i < n; i++) {
        xCoordinates[i].num = i;
        xCoordinates[i].p1 = preference[i].a;
        xCoordinates[i].p2 = preference[i].c;
        xCoordinates[i].isTaken = false;

        yCoordinates[i].num = i;
        yCoordinates[i].p1 = preference[i].b;
        yCoordinates[i].p2 = preference[i].d;
        yCoordinates[i].isTaken = false;
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 0; i < n; i++) {
            if ((xCoordinates[i].p2 < j) || (xCoordinates[i].p1 > j)) {
                continue;
            }

            if (xCoordinates[i].isTaken == 1) {
                continue;
            }
        }
    }

    std::cout << "Next" << std::endl;

    vector<Position> res(n);
    for (int i = 0; i < res.size(); i++) {
        res[i] = {i + 1, i + 1};
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