#include "censor.h"
#include <cmath>

using namespace std;

std::string findBannedWord() {
    const int wordLength = 4;
    const int messageLength = 10000;
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    string text;

    for (int i = 0; i < alphabet.length(); ++i) {
        for (int j = 0; j < alphabet.length(); ++j) {
            for (int k = 0; k < alphabet.length(); ++k) {
                for (int l = 0; l < alphabet.length(); ++l) {
                    text.append({alphabet[i], alphabet[j], alphabet[k], alphabet[l]});
                }
            }
        }
    }
    bool isFinished = false;
    bool textFound = false;
    int currentIndex = 0;
    string currentText = text.substr(currentIndex, messageLength);

    while (!textFound) {
        if (sendMessage(currentText)) {
            textFound = true;
        } else {
            currentIndex += messageLength;
            currentText = text.substr(currentIndex, messageLength);
        }
    }

    string leftText = currentText.substr(0, (currentText.length()) / 2 + wordLength / 2);
    string rightText = currentText.substr((currentText.length() - 1) / 2 - wordLength / 2,
                                          (currentText.length() - 1) / 2);

    while (!isFinished) {
        if (sendMessage(leftText)) {
            currentText = leftText;
            if (currentText.length() == wordLength) {
                return currentText;
            }
            if (currentText.length() % 2 == 0) {
                leftText = currentText.substr(0, currentText.length() / 2 + wordLength / 2);
                rightText = currentText.substr(currentText.length() / 2 - wordLength / 2,
                                               currentText.length() - (currentText.length() / 2 - wordLength / 2));
            } else {
                leftText = currentText.substr(0, currentText.length() / 2 + wordLength / 2);
                rightText = currentText.substr((currentText.length() / 2 + 1 - wordLength / 2),
                                               currentText.length() / 2 + wordLength / 2);
            }
        } else {
            currentText = rightText;
            if (currentText.length() == wordLength) {
                return currentText;
            }
            if (currentText.length() % 2 == 0) {
                leftText = currentText.substr(0, currentText.length() / 2 + wordLength / 2);
                rightText = currentText.substr(currentText.length() / 2 - wordLength / 2,
                                               currentText.length() - (currentText.length() / 2 - wordLength / 2));
            } else {
                leftText = currentText.substr(0, currentText.length() / 2 + wordLength / 2);
                rightText = currentText.substr((currentText.length() / 2 + 1 - wordLength / 2),
                                               currentText.length() / 2 + wordLength / 2);
            }
        }
    }
}