#include <iostream>
#include <vector>

int getWaterBetweenSteps(std::vector<int> stepsVector);

int main()
{
    std::vector<int> stepsVector{3, 0, 0, 1};
    int waterVolume = getWaterBetweenSteps(stepsVector);
    std::cout << "Water Volume " + waterVolume << std::endl;
    return 0;
}

int getWaterBetweenSteps(std::vector<int> stepsVector)
{
    int volumeOfWater = 0;
    int currentVolumeOfStairs = 0;
    int leftIndex = 0;
    int rightIndex = 0;
    int leftHeight = stepsVector[0];
    int rightHeight = 0;
    for (int i = 0; i < stepsVector.size() - 1; i++)
    {
        rightHeight = stepsVector[i + 1];
        if (rightHeight >= leftHeight)
        {
            volumeOfWater += (rightIndex - leftIndex - 1) * std::min(leftHeight, rightHeight);
            volumeOfWater -= currentVolumeOfStairs;
            currentVolumeOfStairs = 0;
            leftIndex = i;
            leftHeight = stepsVector[i];
        }
        else
        {
            currentVolumeOfStairs += stepsVector[i + 1];
        }
    }
    return volumeOfWater;
}