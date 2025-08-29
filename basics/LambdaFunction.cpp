#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void ForEach(const std::vector<int> &values, const std::function<void(int)> &func)
{
    for (int value : values)
    {
        func(value);
    }
}

int main()
{
    int d = 3;
    std::vector<int> values{1, 5, 4, 2, 3};
    std::for_each(values.begin(), values.end(), [d](int x)
                  {
        if (x % d == 0)
        {
            std::cout << x << " is divisible by " << d <<"\n";
        }
        else
        {
            std::cout << x << " is not divisible by " << d <<"\n";
        } });

    int a = 5;

    auto lambda = [=](int value)
    {
        std::cout << "Value: " << value << std::endl;
    };

    auto it = std::find_if(values.begin(), values.end(), [](int value)
                           { return value > 3; });
    std::cout << *it << std::endl;

    ForEach(values, lambda);
}
