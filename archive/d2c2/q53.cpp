#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) \
  {             \
  }
#define debarr(a, n) \
  {                  \
  }
#define debmat(mat, row, col) \
  {                           \
  }
#endif

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  int k;
  cin >> s >> k;

  int n = s.size();

  vector<int> mx(26);

  vector<vector<bool>> forb(26, vector<bool> (26, 0));
  for (int i = 0; i < k; i++) {
      char x, y;
      cin >> x >> y;
      forb[x - 'a'][y - 'a'] = true;
      forb[y - 'a'][x - 'a'] = true;
  }

  for (int i = 0; i < n; i++) {
    int temp = 0;
    for (int j = 0; j < 26; j++) {
      if(!forb[s[i] - 'a'][j]){
        temp = max(temp, mx[j] + 1);
      }
    }
    mx[s[i] - 'a'] = temp;
  }
  int ans = n - *max_element(mx.begin(), mx.end());
  cout << ans << "\n";

  return 0;
}
