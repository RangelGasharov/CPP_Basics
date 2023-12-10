#include <algorithm>
#include <iostream>
#include "censor.h"
#include "censor.cpp"

using namespace std;

static string bad;
static int cnt;

static void WA(const string &msg) {
    cerr << msg << "\n";
    exit(1);
}

bool sendMessage(const string &m) {
    cnt++;
    if (m.size() > 10000)
        WA("Nachricht zu lang");
    for (char c: m)
        if (c < 'a' || c > 'z')
            WA("Nachricht enhaelt nicht nur a-z");
    for (int i = 0; i + 3 < m.size(); i++)
        if (equal(bad.begin(), bad.end(), m.begin() + i))
            return true;
    return false;
}

int main() {
    cin >> bad;
    auto ans = findBannedWord();
    if (bad == ans)
        cout << "Ok, " << cnt << " Nachrichten\n";
    else
        cout << "Falsch, " << ans << " " << bad << "\n";
    return 0;
}
