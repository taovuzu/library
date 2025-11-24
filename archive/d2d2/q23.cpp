#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dp;

bool rec(int mask) {
  if (dp[mask] != -1) return dp[mask];
  for (int i = 0; i < n - 1; i++) {
    if (!(mask & (1 << i))) continue;

    // Step move
    int stepTo = i + 1;
    if (stepTo == n - 1) {  // checker disappears
      int nextMask = mask & ~(1 << i);
      if (!rec(nextMask)) return dp[mask] = 1;
    } else if (!(mask & (1 << stepTo))) {
      int nextMask = (mask & ~(1 << i)) | (1 << stepTo);
      if (!rec(nextMask)) return dp[mask] = 1;
    }

    // Jump move
    int jumpTo = i + 3;
    if (jumpTo < n) {
      if ((mask & (1 << (i + 1))) && (mask & (1 << (i + 2)))) {
        if (jumpTo == n - 1) {  // disappears
          int nextMask = mask & ~(1 << i);
          if (!rec(nextMask)) return dp[mask] = 1;
        } else if (!(mask & (1 << jumpTo))) {
          int nextMask = (mask & ~(1 << i)) | (1 << jumpTo);
          if (!rec(nextMask)) return dp[mask] = 1;
        }
      }
    }
  }
  return dp[mask] = 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  n = (int)s.size();

  int mask = 0;
  for (int i = 0; i < n - 1; i++)
    if (s[i] == 'o') mask |= (1 << i);

  dp.assign(1 << (n - 1), -1);
  cout << (rec(mask) ? "YES\n" : "NO\n");

  return 0;
}
