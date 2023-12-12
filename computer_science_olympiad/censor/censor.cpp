#include "censor.h"
#include <iostream>

using namespace std;

std::string findBannedWord() {
    const int wordLength = 4;
    const int messageLength = 10000;
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    
    string text;
    bool isFinished = false;

    for (int i = 0; i < alphabet.length(); ++i) {
        for (int j = 0; j < alphabet.length(); ++j) {
            for (int k = 0; k < alphabet.length(); ++k) {
                for (int l = 0; l < alphabet.length(); ++l) {
                    text.append({alphabet[i], alphabet[j], alphabet[k], alphabet[l]});
                }
            }
        }
    }

    int currentIndex = 0;
    string currentText = text.substr(currentIndex, messageLength);
    while (!isFinished) {
        if (sendMessage(currentText)) {
            isFinished = true;
        } else {
            currentIndex += messageLength;
            currentText = text.substr(currentIndex, messageLength);
        }
    }

    return "";
}