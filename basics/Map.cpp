#include <iostream>
#include <map>

using namespace std;


int main() {
    map<char, int> mapExample = {
            {'A', 10},
            {'B', 12},
            {'C', 20}
    };

    mapExample['U'] = 9;
    pair<char, int> p1('S', 14);
    mapExample.insert(p1);
    cout << p1.first << ":" << p1.second << endl;

    cout << mapExample['S'] << endl;
    mapExample.erase(p1.first);
    cout << mapExample['S'] << endl;
    mapExample.insert(pair<char, int>('O', 11));
    cout << mapExample['U'] << endl;
    cout << "Size of map: " << mapExample.size() << endl;

    for (auto itr = mapExample.begin(); itr != mapExample.end(); itr++) {
        cout << (*itr).first << endl;
        cout << itr->second << endl;
    }

    string sentence = "This is a test sentence";

    map<char, int> freq;

    for (int i = 0; i < sentence.length(); i++) {
        char letter = sentence[i];

        if (freq.find(letter) == freq.end()) {
            freq[letter] = 0;
        }

        freq[letter]++;
    }
    for (auto itr = freq.begin(); itr != freq.end(); itr++) {
        cout << itr->first << ": " << itr->second << endl;
    }
}