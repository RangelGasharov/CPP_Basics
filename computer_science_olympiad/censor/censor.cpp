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

    string leftText = currentText.substr(0, ceil((currentText.length()) / 2 + wordLength - 1));
    string rightText = currentText.substr((currentText.length() - 1) / 2 + 1, currentText.length() - 1);

    while (!isFinished) {
        if (sendMessage(leftText)) {
            if (leftText.length() <= wordLength * 2) {
                int offset = 0;
                while (true) {
                    string a = leftText.substr(offset, wordLength);
                    if (sendMessage(a)) {
                        return a;
                    }
                    offset += 1;
                }
            }
            currentText = leftText;
            leftText = currentText.substr(0, ceil((currentText.length()) / 2 + wordLength - 1));
            rightText = currentText.substr(ceil(currentText.length() / 2) - (wordLength - 1), currentText.length() - 1);
            cout << "l," + leftText << endl;
            cout << "r," + rightText << endl;
        } else {
            currentText = rightText;
            leftText = currentText.substr(0, ceil(currentText.length() / 2 + wordLength - 1));
            rightText = currentText.substr(ceil(currentText.length() / 2) - (wordLength - 1), currentText.length() - 1);
            cout << "l," + leftText << endl;
            cout << "r," + rightText << endl;

            if (rightText.length() <= wordLength * 2) {
                int offset = 0;
                while (true) {
                    string a = rightText.substr(offset, wordLength);
                    if (sendMessage(a)) {
                        return a;
                    }
                    offset += 1;
                }
            }
        }
    }
}