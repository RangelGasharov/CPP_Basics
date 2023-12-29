#include <vector>
#include <utility>

struct Preference
{
  int a,b,c,d;
};

struct Position
{
  int r, c;
};

std::vector<Position> solve(const std::vector<Preference> &preferences);
