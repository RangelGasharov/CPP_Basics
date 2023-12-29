#include "matura.h"

using namespace std;

std::vector<Position> solve(const std::vector<Preference> &preference)
{
  const int n = preference.size();

  // TODO: deine Implementierung

  vector<Position> res(n);
  for (int i = 0; i < res.size(); i++)
  {
    res[i] = {i + 1, i + 1};
  }


  return res;
}
