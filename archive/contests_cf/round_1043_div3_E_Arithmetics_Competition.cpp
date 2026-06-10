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
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m ; i++) {
    cin >> b[i];
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());

  vector<int> sa(n + 1), sb(m + 1);
  for (int i_ = 1; i_ <= n; i_++) sa[i_] = a[i_ - 1] + sa[i_ - 1];
  for (int i_ = 1; i_ <= m; i_++) sb[i_] = b[i_ - 1] + sb[i_ - 1];

  vector<array<int, 2>> c(n + m + 1);
  for (int i = 1, l = 0, r = 0; i < c.size(); i++) {
    if (l < n && r < m) {
      if (a[l] < b[r]) r++;
      else l++;
    }
    else if (l < n) l++;
    else r++;
    c[i] = {l, r};
  }

  while(q--) {
    int x, y, z;
    cin >> x >> y >> z;
   
    if (c[z][0] > x) {
      cout << sa[x] + sb[z - x] << "\n";
    }
    else if (c[z][1] > y) {
      cout << sa[z - y] + sb[y] << "\n";
    }
    else {
      cout << sa[c[z][0]]  + sb[c[z][1]] << "\n";
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
