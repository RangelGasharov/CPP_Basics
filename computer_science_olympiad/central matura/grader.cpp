#include <cstdio>

#include "matura.h"

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  vector<Preference> preferences(n);
  for (Preference &p : preferences)
    scanf("%d %d %d %d", &p.a, &p.b, &p.c, &p.d);

  const vector<Position> result = solve(preferences);
  if (result.empty())
    printf("-1\n");
  else
    for (int i = 0; i < n; i++)
      printf("%d %d\n", result[i].r, result[i].c);
  return 0;
}