#include  <iostream>
#include <list>
#include <cstring>

using namespace std;

class HashTable {
private:
    static const int hashGroups = 10;
    list<pair<int, string>> table[hashGroups];
public:
    bool isEmpty() const;

    int hashFunction(int key);

    void insertItem(int key, string value);

    void removeItem(int key);

    string searchTable(int key);

    void printTable();
};

bool HashTable::isEmpty() const {
    int sum{};
    for (int i{}; i < hashGroups; i++) {
        sum += table[i].size();
    }
    if (!sum) {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key) {
    return key % hashGroups;
}

void HashTable::insertItem(int key, std::string value) {
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;

    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            cout << "[WARNING] Key exists. Value replaced." << endl;
            break;
        }
    }

    if (!keyExists) {
        cell.emplace_back(key, value);
    }
    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;

    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "[INFO] Item removed." << endl;
            break;
        }
    }

    if (!keyExists) {
        cout << "[WARNING] Item not found. Pair not removed." << endl;
    }

    return;
}

void HashTable::printTable() {
    for (int i{}; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;
        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            cout << "[INFO] Key: " << bItr->first << " Value: " << bItr->second << endl;
        }
    }
    return;
}

int main() {
    HashTable HT;
    if (HT.isEmpty()) {
        cout << "Hash Table is empty. Everything is correct!" << endl;
    } else {
        cout << "Hash Table is not empty. Something is wrong!" << endl;
    }
    HT.insertItem(120, "Ella");
    HT.insertItem(121, "Tom");
    HT.insertItem(122, "Mike");
    HT.insertItem(123, "Eva");
    HT.insertItem(124, "Robert");
    HT.insertItem(125, "Sylvia");
    HT.insertItem(126, "Anton");
    HT.insertItem(127, "Anna");
    HT.insertItem(127, "Lisa");

    HT.printTable();

    HT.removeItem(124);
    HT.removeItem(100);

    if (HT.isEmpty()) {
        cout << "Hash Table is empty. Something is wrong!" << endl;
    } else {
        cout << "Hash Table is not empty. Everything is correct!" << endl;
    }

    HT.printTable();

    return 0;
}
