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
  cin >> n;

  vector<int> a(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] = i;
  }

  while (true) {
    int i = -1;
    for (int j = 0; j < n; j++) {
      if (mp[a[j] - 1] > j && mp[a[j] - 2] > j) {
        if(i == -1 || a[j] < a[i]) i = j;
      }
    }
    if (i == -1) break;
    while (a[i] >=  3) {
      if (mp[a[i] - 1] < i  || mp[a[i] - 2] < i) break;
      int px = mp[a[i] - 2];mp[a[j] - 1] 
      int py = mp[a[i] - 1];
      a[px]++, a[py]++;
      a[i] -= 2;
      mp[a[i]] = i;
      mp[a[px]] = px;
      mp[a[py]] = py;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
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
