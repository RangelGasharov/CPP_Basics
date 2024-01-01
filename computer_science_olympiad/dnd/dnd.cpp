#include "dnd.h"
#include <sstream>
#include <string>

using namespace std;

tuple<int, int, int> getNoteComponents(string numberCombination) {
    int originDoor, checkedUntil, nextDoor;
    int separatorOne, separatorTwo;

    for (int i = 0; i <= numberCombination.size() - 1; i++) {
        if (numberCombination[i] == '_') { separatorOne = i; }
        if (numberCombination[i] == '/') { separatorTwo = i; }
    }

    originDoor = stoi(numberCombination.substr(0, separatorOne));
    checkedUntil = stoi(numberCombination.substr(separatorOne + 1, separatorTwo - separatorOne - 1));
    nextDoor = stoi(numberCombination.substr(separatorTwo + 1, numberCombination.size() - separatorTwo - 1));
    return {originDoor, checkedUntil, nextDoor};
}

string generateNote(int originDoor, int checkedUntil, int nextDoor) {
    std::stringstream numberCombinationStream;
    numberCombinationStream << originDoor << "_" << checkedUntil << "/" << nextDoor;
    std::string numberCombination = numberCombinationStream.str();
    return numberCombination;
}

void findExit() {
    int originDoor = 0;
    int checkedUntil = 0;
    int nextDoor = 0;
    int amountOfDoors = 0;
    string currentNote = "";

    while (true) {
        amountOfDoors = numOfDoors();
        currentNote = readNote();

        if (currentNote.empty()) {
            checkedUntil = 0;
            nextDoor = 1;
            if (nextDoor != originDoor) {
                currentNote = generateNote(originDoor, checkedUntil, nextDoor);
                takeNote(currentNote);
            } else if (nextDoor + 1 <= amountOfDoors) {
                nextDoor += 1;

                int originDoorCopy = takeDoor(nextDoor);
                takeDoor(originDoorCopy);

                checkedUntil = nextDoor;
                currentNote = generateNote(originDoor, checkedUntil, nextDoor);
                takeNote(currentNote);
            } else {
                originDoor = takeDoor(originDoor);
            }
        } else {
            auto [value1, value2, value3] = getNoteComponents(currentNote);
            originDoor = value1;
            checkedUntil = value2;
            nextDoor = value3;

            if (nextDoor <= amountOfDoors && nextDoor) {
                if (checkedUntil == nextDoor && nextDoor != 0) {
                    originDoor = takeDoor(nextDoor);
                    if (!readNote().empty()) {
                        takeDoor(originDoor);
                        nextDoor += 1;
                        checkedUntil = nextDoor;
                        currentNote = generateNote(originDoor, checkedUntil, nextDoor);
                        takeNote(currentNote);
                    }
                } else if (nextDoor + 1 <= amountOfDoors) {
                    nextDoor += 1;
                    currentNote = generateNote(originDoor, checkedUntil, nextDoor);
                    takeNote(currentNote);

                    int originDoorCopy = originDoor;
                    originDoor = takeDoor(nextDoor);
                    takeDoor(originDoor);

                    checkedUntil = nextDoor;
                    currentNote = generateNote(originDoorCopy, checkedUntil, nextDoor);
                    takeNote(currentNote);
                }
            }
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
*/