#include <iostream>
#include <vector>

typedef std::vector<std::pair<std::string, int>> pairlist_t;
using text_t = std::string;

int main()
{
    pairlist_t pairList = {{"test", 10}, {"test", 30}};
    text_t text = "Test";

    int correct = 8;
    int totalQuestions = 10;
    double score = correct / (double)totalQuestions * 100;

    std::cout << score << "%" << std::endl;

    return 0;
}