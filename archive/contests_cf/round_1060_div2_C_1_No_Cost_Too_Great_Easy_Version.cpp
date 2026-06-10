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

const int N = 200200;
vector<vector<int>> pf(N);

void solve() {
  int n, x;
  cin >> n;

  vector<int> a(n);
  map<int, int> cnt;
  bool flag = false;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (auto it : pf[a[i]]) {
      if (it > 1 && cnt[it]) flag = true;
      cnt[it]++;
    }
  }

  for (int i = 0; i < n; i++) {
    cin >> x;
  }

  if (flag) {
    cout << 0 << "\n";
  }
  else {
    for (int i = 0; i < n; i++) {
      for (auto it : pf[a[i] + 1]) {
        if (it > 1 && cnt[it]) flag = true;
      }
    }
    if (flag) {
      cout << 1 << "\n";
    }
    else {
      cout << 2 << "\n";
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  pf[1].push_back(1);
  for (int i = 2; i < N; i++) {
    if (!pf[i].empty()) continue;
    for (int j = i; j < N; j += i) {
      pf[j].push_back(i);
    }
  }

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
