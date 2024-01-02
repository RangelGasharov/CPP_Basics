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
                std::cout << "Option E1" << std::endl;
                currentNote = generateNote(originDoor, checkedUntil, nextDoor);
                std::cout << currentNote << std::endl;
                takeNote(currentNote);

                int originDoorCopy = takeDoor(nextDoor);
                takeDoor(originDoorCopy);

                checkedUntil = nextDoor;
                currentNote = generateNote(originDoor, checkedUntil, nextDoor);
                std::cout << currentNote << std::endl;
                takeNote(currentNote);
            } else if (nextDoor + 1 <= amountOfDoors) {
                std::cout << "Option E2" << std::endl;
                nextDoor += 1;

                int originDoorCopy = takeDoor(nextDoor);
                takeDoor(originDoorCopy);

                checkedUntil = nextDoor;
                currentNote = generateNote(originDoor, checkedUntil, nextDoor);
                std::cout << currentNote << std::endl;
                takeNote(currentNote);
            } else {
                std::cout << "Option E3" << std::endl;
                takeNote("x");
                takeDoor(originDoor);
            }
        } else {
            auto [value1, value2, value3] = getNoteComponents(currentNote);
            originDoor = value1;
            checkedUntil = value2;
            nextDoor = value3;
            amountOfDoors = numOfDoors();
            std::cout << "amountOfDoors " << amountOfDoors << std::endl;

            if (nextDoor <= amountOfDoors) {
                if (checkedUntil == nextDoor && nextDoor != 0) {
                    std::cout << "Option B1" << std::endl;
                    std::cout << currentNote << std::endl;
                    originDoor = takeDoor(nextDoor);
                    if (!readNote().empty()) {
                        takeDoor(originDoor);
                        currentNote = readNote();
                        auto [value1, value2, value3] = getNoteComponents(currentNote);
                        originDoor = value1;
                        checkedUntil = value2;
                        nextDoor = value3;
                        amountOfDoors = numOfDoors();

                        if (nextDoor + 1 <= amountOfDoors) {
                            nextDoor += 1;

                            int originDoorCopy = takeDoor(nextDoor);
                            takeDoor(originDoorCopy);

                            checkedUntil = nextDoor;
                            currentNote = generateNote(originDoor, checkedUntil, nextDoor);
                            std::cout << currentNote << std::endl;
                            takeNote(currentNote);
                        } else {
                            takeDoor(originDoor);
                        }
                    }

                } else if (nextDoor + 1 <= amountOfDoors) {
                    std::cout << "Option B2" << std::endl;
                    nextDoor += 1;
                    currentNote = generateNote(originDoor, checkedUntil, nextDoor);
                    std::cout << currentNote << std::endl;
                    std::cout << currentNote << std::endl;
                    takeNote(currentNote);

                    int originDoorCopy = originDoor;
                    originDoor = takeDoor(nextDoor);
                    takeDoor(originDoor);

                    checkedUntil = nextDoor;
                    currentNote = generateNote(originDoorCopy, checkedUntil, nextDoor);
                    std::cout << currentNote << std::endl;
                    takeNote(currentNote);
                }
            } else {
                currentNote = readNote();
                auto [value1, value2, value3] = getNoteComponents(currentNote);
                originDoor = value1;
                checkedUntil = value2;
                nextDoor = value3;
                std::cout << "Out" << std::endl;
                std::cout << currentNote << std::endl;
                takeDoor(originDoor);
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