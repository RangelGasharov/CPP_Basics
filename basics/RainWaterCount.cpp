#include <iostream>
#include <vector>

int getWaterBetweenSteps(std::vector<int> stepsVector)
{
    int volumeOfWater{0};
    int leftIndex{0};
    int rightIndex = stepsVector.size() - 1;
    int leftMaxHeight{stepsVector[leftIndex]};
    int rightMaxHeight{stepsVector[rightIndex]};
    while (leftIndex < rightIndex)
    {
        if (leftMaxHeight < rightMaxHeight)
        {
            leftIndex += 1;
            leftMaxHeight = std::max(leftMaxHeight, stepsVector[leftIndex]);
            volumeOfWater += leftMaxHeight - stepsVector[leftIndex];
        }
        else
        {
            {
                rightIndex -= 1;
                rightMaxHeight = std::max(rightMaxHeight, stepsVector[rightIndex]);
                volumeOfWater += rightMaxHeight - stepsVector[rightIndex];
            }
        }
    }
    return volumeOfWater;
}

int main()
{
    std::vector<int> stepsVector{0, 1, 1, 0, 3, 2, 1, 0, 2, 3};
    int waterVolume = getWaterBetweenSteps(stepsVector);
    std::cout << "" << std::endl;
    std::cout << "water volume: " + waterVolume << std::endl;
    return 0;
}
