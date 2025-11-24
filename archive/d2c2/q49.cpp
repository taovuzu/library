#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int s, w, c, k, m;
  while ( cin >> s >> w >> c >> k >> m) {
    int r = 10000;
    multiset<int> xt;
    for (int i = 0; i < k; i++) {
      xt.insert(s + m * (i + 1));
    }

    int ans = LLONG_MAX, digAvail = 0;
    while(r > 0){
      r -= c;
      int temp = *xt.begin();
      xt.erase(xt.begin());

      ans = max(temp, digAvail) + s + w;
      digAvail = max(temp, digAvail) + w;
      xt.insert(ans + s);
    }

    cout << ans << "\n";

  }

  return 0;
}