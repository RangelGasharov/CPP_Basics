#include "censor.h"
#include <iostream>

std::string findBannedWord() {
    const int wordLength = 4;
    const int messageLength = 10000;
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < alphabet.length(); ++i) {
        for (int j = 0; j < alphabet.length(); ++j) {
            for (int k = 0; k < alphabet.length(); ++k) {
                for (int l = 0; l < alphabet.length(); ++l) {
                    std::string testWord = {alphabet[i], alphabet[j], alphabet[k], alphabet[l]};

                    if (sendMessage(testWord)) {
                        return testWord;
                    }
                }
            }
        }
    }
    return "";
}