#include "dnd.h"
#include <sstream>
#include <string>

using namespace std;

tuple<int, int, int> getNoteComponents(string numberCombination) {
    int originDoor, nextDoor, isChecked;
    int separatorOne, separatorTwo;

    for (int i = 0; i <= numberCombination.size() - 1; i++) {
        if (numberCombination[i] == '_') { separatorOne = i; }
        if (numberCombination[i] == '/') { separatorTwo = i; }
    }

    originDoor = stoi(numberCombination.substr(0, separatorOne));
    nextDoor = stoi(numberCombination.substr(separatorOne + 1, separatorTwo - separatorOne - 1));
    isChecked = stoi(numberCombination.substr(separatorTwo + 1, numberCombination.size() - separatorTwo - 1));
    return {originDoor, nextDoor, isChecked};
}

string generateNote(int originDoor, int nextDoor, int isChecked) {
    std::stringstream numberCombinationStream;
    numberCombinationStream << originDoor << "_" << nextDoor << "/" << isChecked;
    std::string numberCombination = numberCombinationStream.str();
    return numberCombination;
}

void findExit() {
    int originDoor = 0;
    int originDoorCopy = 0;
    int nextDoor = 0;
    int isChecked = 0;
    int amountOfDoors = 0;
    int currentState = 1;
    string currentNote = "";

    while (true) {
        currentState = 1;

        while (currentState == 1) {
            currentNote = readNote();

            if (currentNote.empty()) {
                currentState = 2;
                continue;
            } else {
                auto [value1, value2, value3] = getNoteComponents(currentNote);
                originDoor = value1;
                nextDoor = value2;
                isChecked = value3;

                if (isChecked == 1) {
                    takeDoor(nextDoor);
                } else {
                    currentState = 2;
                    continue;
                }
            }
        }

        while (currentState = 2) {
            amountOfDoors = numOfDoors();
            currentNote = readNote();

            if (currentNote.empty()) {
                nextDoor = 1;
                if (nextDoor == originDoor) {
                    if (nextDoor + 1 <= amountOfDoors) {
                        nextDoor += 1;
                    } else {
                        currentState = 3;
                        continue;
                    }
                }

                currentNote = generateNote(originDoor, nextDoor, isChecked);
                takeNote(currentNote);

                originDoorCopy = takeDoor(nextDoor);
                currentNote = readNote();
                takeDoor(originDoorCopy);


                isChecked = 1;
                currentNote = generateNote(originDoor, nextDoor, isChecked);
                takeNote(currentNote);
                isChecked = 0;
                originDoor = takeDoor(nextDoor);

            } else {
                currentNote = readNote();
                amountOfDoors = numOfDoors();
                auto [value1, value2, value3] = getNoteComponents(currentNote);
                originDoor = value1;
                nextDoor = value2;
                isChecked = value3;

                if (isChecked == 0) {
                    nextDoor += 1;
                    if (nextDoor == originDoor) {
                        if (nextDoor + 1 <= amountOfDoors) {
                            nextDoor += 1;
                        } else {
                            takeDoor(originDoor);
                            continue;
                        }
                    }
                }

                currentNote = generateNote(originDoor, nextDoor, isChecked);
                takeNote(currentNote);

                originDoorCopy = takeDoor(nextDoor);
                currentNote = readNote();

                if (!currentNote.empty()) {
                    auto [value1, value2, value3] = getNoteComponents(currentNote);
                    originDoor = value1;
                    nextDoor = value2;
                    isChecked = value3;

                    if ((nextDoor == amountOfDoors && isChecked == 1) || (amountOfDoors == 1)) {
                        takeDoor(originDoor);
                        currentNote = readNote();
                        amountOfDoors = numOfDoors();

                        auto [value1, value2, value3] = getNoteComponents(currentNote);
                        originDoor = value1;
                        nextDoor = value2;
                        isChecked = value3;

                        nextDoor += 1;
                        if (nextDoor == originDoor) {
                            if (nextDoor + 1 <= amountOfDoors) {
                                nextDoor += 1;
                            } else {
                                takeDoor(originDoor);
                            }
                        }
                    }
                }

                takeDoor(originDoorCopy);
                isChecked = 1;
                currentNote = generateNote(originDoor, nextDoor, isChecked);
                takeNote(currentNote);
                isChecked = 0;
                originDoor = takeDoor(nextDoor);
            }
        }

        while (currentState == 3) {
            auto [value1, value2, value3] = getNoteComponents(currentNote);
        }
    }
}

/*
6 6
1 2
1 3
3 4
4 5
5 3
5 6
1
2
 ---

7 8
1 2
1 3
1 4
2 3
2 6
3 4
3 7
4 5
1
6
*/