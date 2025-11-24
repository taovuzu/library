#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin >> s;

  int a, b;
  cin >> a >> b;

  int n = s.size();
  set<int> xt;
  int temp = 0;
  for (int i = 0; i < n; i++) {
    int x = s[i] - '0';
    temp *= 10;
    temp += x;
    temp %= a;
    if (temp == 0) {
      xt.insert(i);
    }
  }

  temp = 0;
  int div = 1, ans = -1;
  for (int i = n - 1; i >= 0; i--) {
    int x = s[i] - '0';
    temp = (div * x + temp) % b;
    div *= 10;
    div %= b;

    if (temp == 0 && x != 0) {
      if (xt.find(i - 1) != xt.end()) {
        ans = i;
        break;
      }
    }
  }

  if (ans == -1) {
    cout << "NO";
  }
  else {
    cout << "YES" << "\n";
    cout << s.substr(0, ans) << "\n" << s.substr(ans, n - ans + 1);
  }

  return 0;
}
