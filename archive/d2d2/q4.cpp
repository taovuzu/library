// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
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

void solve() {
  int x, y, z, m, n, ans = 0;
  cin >> x >> y >> z >> m >> n;
  vector<int> a(n);
  a[0] = x;
  if (a[0] % m == 0) ans++;
  map<int, int> mp;
  mp[0]++, mp[a[0] % m]++;
  for (int i = 1; i < n; i++) {
    a[i] = ((a[i - 1] * y + z) % m) + 1;
  }
  for (int i = 1; i < n; i++) {
    a[i] = (a[i] + a[i - 1]) % m;
    ans += mp[a[i]];
    mp[a[i]]++;
  }
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    cout << "Case " << t_ << ": ";
    solve();
  }

  return 0;
}
