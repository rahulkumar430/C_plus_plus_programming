#include<bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<string, int> &p1,
               const pair<string, int> &p2)
{
  if (p1.second == p2.second)
  {
    return p1.first < p2.first;
  }
  return p1.second > p2.second;
}

int main() {
  int x, n;
  cin >> x >> n;

  vector< pair <string, int>> employees;

  string name[n];
  int salary[n];

  for (int i = 0; i < n; i++) {
    cin >> name[i];
    cin >> salary[i];
    employees.push_back(make_pair(name[i], salary[i]));
  }

  /*  for (int i=0; i<n; i++)
      {
          cout << employees[i].first << " "
               << employees[i].second << endl;

      }  */

  sort(employees.begin(), employees.end(), sortbysec);

  for (int i = 0; i < n; i++) {
    if (employees[i].second >= x) {
      cout << employees[i].first << " " << employees[i].second << endl;
    }
  }

  return 0;
}