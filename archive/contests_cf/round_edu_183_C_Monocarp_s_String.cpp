// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv)
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifdef LOCAL
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

void solve() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    if (i) a[i] = a[i - 1], b[i] = b[i - 1];
    if (s[i] == 'a') a[i]++;
    else b[i]++;
  }

  int ans = a[n - 1] == b[n - 1] ? 0 : n;
  map<int, int> mp;
  mp[0] = -1;
  for (int i = 0; i < n; i++) {
    int target = b[n - 1] - a[n - 1] + a[i] - b[i];
    if (mp.count(target)) {
      ans = min(ans, i - mp[target]);
    }
    mp[a[i] - b[i]] = i;
  }

  cout << (ans == n ? -1 : ans) << "\n";
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
