#include <cstdio>
#include <vector>

using namespace std;

struct Preference {
    int a, b, c, d;
};

struct Position {
    int r, c;
};

std::vector<Position> solve(const std::vector<Preference> &preference) {
    const int n = preference.size();

    // TODO: deine Implementierung

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