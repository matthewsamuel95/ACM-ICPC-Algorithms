#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int k;
  cin >> k;

  int n;
  cin >> n;

  unordered_map<string, int> m;
  for (size_t i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    m[s]++;
  }

  vector<pair<string, int>> v;
  for (const auto &it : m)
  {
    v.push_back(make_pair(it.first, it.second));
  }

  sort(v.begin(), v.end(), [](const pair<string, int> &a, const pair<string, int> &b) -> bool {
    return a.second > b.second || (a.second == b.second && a.first < b.first);
  });

  for (size_t i = 0; i < k && i < v.size(); i++)
  {
    cout << v[i].first << endl;
  }
}