#include <string>
#include <iostream>

std::string getRank(int level)
{
    return level > 5 ? level > 10 ? "Master" : "Intermediate" : "Beginner";
}

int main()
{
    std::cout << getRank(5) << std::endl;
    std::cout << getRank(10) << std::endl;
    std::cout << getRank(11) << std::endl;
    return 0;
}