// Count number of substrings-palindromes in given string s in O(|s|) time
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  string t;
  for (char x : s) {
    t += x;
    t += '#';
  }
  int n = t.size();
  long long ans = 0;
  vector<int> rad(n);
  for (int i = 0, l = 0, r = 0; i < n; ++i) {
    if (i < r) {
      rad[i] = min(r - i, rad[l + r - i]);
    }
    while (i + rad[i] < n && i - rad[i] >= 0 && t[i + rad[i]] == t[i - rad[i]]) {
      ++rad[i];
    }
    if (i + rad[i] > r) {
      l = i - rad[i];
      r = i + rad[i];
    }
    if (i % 2 == 0) {
      ans += (rad[i] + 1) / 2 - 1;
    } else {
      ans += rad[i] / 2;
    }
  }
  cout << ans << '\n';
}

