// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv hr)
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
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m), mp(n + m + 5);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  vector<int> c(n + m + 5);
  for (int i = 1; i <= n + m; i++) {
    int cnt = mp[i];
    if (cnt) {
      for (int j = i; j <= n + m; j += i) {
        c[j] += cnt;
      }
    }
  }

  int u = 0, v = 0, w = 0;
  for (int i = 0; i < m; i++) {
    if (c[b[i]] == n) v++;
    else if (c[b[i]] == 0) w++;
    else u++;
  }

  if (u % 2 == 1) {
    if (v >= w) {
      cout << "Alice" << "\n";
    }
    else {
      cout << "Bob" << "\n";
    }
  }
  else {
    if (v > w) {
      cout << "Alice" << "\n";
    }
    else {
      cout << "Bob" << "\n";
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
