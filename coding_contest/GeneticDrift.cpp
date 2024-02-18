#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Position {
    int x, y;
};

std::vector<int> getPermutations(std::string permutationString) {
    std::string currentNumberAsString;
    int currentNumber = 0;
    std::vector<int> result;
    for (int i = 0; i < permutationString.size(); i++) {
        if (permutationString[i] != ' ') {
            currentNumberAsString += permutationString[i];
        } else {
            currentNumber = std::stoi(currentNumberAsString);
            result.push_back(currentNumber);
            currentNumberAsString = "";
        }
    }
    currentNumber = std::stoi(currentNumberAsString);
    result.push_back(currentNumber);
    currentNumberAsString = "";
    return result;
}

bool compareByXCoordinates(const Position &a, const Position &b) {
    return a.x < b.x;
}

void printPermutations(std::vector<int> permutations) {
    for (int i = 0; i < permutations.size(); i++) {
        std::cout << permutations[i] << " ";
    }
    std::cout << std::endl;
}

void printOrientedPairs(std::vector<Position> orientedPairs) {
    for (int i = 0; i < orientedPairs.size(); i++) {
        std::cout << orientedPairs[i].x << " " << orientedPairs[i].y << " ";
    }
    std::cout << std::endl;
}

std::vector<Position> getOrientedPairs(std::vector<int> permutations) {
    int permutationLength = permutations[0];
    permutations.erase(permutations.begin());
    std::vector<Position> orientedPairs;

    for (int i = 0; i < permutationLength; i++) {
        int x = permutations[i];
        int xAbsolute = abs(x);

        for (int j = i; j < permutationLength; j++) {
            int y = permutations[j];
            int yAbsolute = abs(y);
            if ((xAbsolute - yAbsolute == 1 || xAbsolute - yAbsolute == -1) && ((x > 0 && y < 0) || (x < 0 && y > 0))) {
                orientedPairs.push_back({x, y});
            }
        }
    }
    int orientedPairsLength = orientedPairs.size();
    std::sort(orientedPairs.begin(), orientedPairs.end(), compareByXCoordinates);
    orientedPairs.insert(orientedPairs.begin(), {orientedPairsLength});

    return orientedPairs;
}

int main() {
    std::vector<int> permutations_1 = getPermutations("8 0 3 1 6 5 -2 4 7");
    std::vector<Position> orientedPairs_1 = getOrientedPairs(permutations_1);
    printOrientedPairs(orientedPairs_1);

    std::vector<int> permutations_2 = getPermutations("9 3 1 6 5 -2 4 -7 8 9");
    std::vector<Position> orientedPairs_2 = getOrientedPairs(permutations_2);
    printOrientedPairs(orientedPairs_2);

    std::vector<int> permutations_3 = getPermutations("8 0 -5 -6 -1 -3 -2 4 7");
    std::vector<Position> orientedPairs_3 = getOrientedPairs(permutations_3);
    printOrientedPairs(orientedPairs_3);


    std::vector<int> permutations_4 = getPermutations("193 125 133 134 135 136 -52 -51"
                                                      " -50 -49 -48 -47 -46 -45 66 67 68 69 70 71 -38 -37 -36 -35 -34"
                                                      " -33 -32 -31 -30 -29 -132 -131 -130 -193 -192 -191 -190 -189"
                                                      " -188 -187 -186 -185 -184 -183 -182 -181 -180 -179 -178 -177"
                                                      " -176 -175 -174 -173 -172 -171 -170 -169 -77 -76 -75 -74 -73"
                                                      " -72 18 19 20 21 22 23 24 25 26 27 28 -164 -163 -65 -64 -63 -62"
                                                      " -61 -60 -59 -58 -57 -56 -55 -54 -53 39 40 41 42 43 44 159 160"
                                                      " 161 162 -17 -16 -15 -14 -13 -12 -11 -10 -9 -8 -7 -6 -5 -4 -3"
                                                      " -2 -1 -168 -167 -166 -165 126 127 128 129 86 87 88 89 90 91"
                                                      " 92 93 94 95 96 -124 -123 -122 -121 -120 -119 -118 -117 -116"
                                                      " -115 -114 -113 -112 -111 -110 -109 -108 -107 -106 -105 -104"
                                                      " -103 -102 -101 -100 -99 -98 -97 153 154 155 156 157 158 -148"
                                                      " -147 -146 -145 -144 -143 -142 -141 -140 -139 -138 -137 -85 -84"
                                                      " -83 -82 -81 -80 -79 -78 -152 -151 -150 -149");
    std::vector<Position> orientedPairs_4 = getOrientedPairs(permutations_4);
    printOrientedPairs(orientedPairs_4);

    return 0;
}
