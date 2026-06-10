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

  vector<array<int, 2>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][1] >> a[i][0]; // a[i] -> {y, x};
  }

  sort(a.begin(), a.end());
  priority_queue<int> pq;
  vector<int> dp(n + 5), dp1(n + 5); // sum, mini
  int sum = 0;
  int res = 0;

  for (int i = n - 1; i >= 0; i--) {
    pq.insert(a[i][1]);
    sum += pq.front();

    while (pq.size() > a[i][0]) {
      sum -= pq.front();
      pq.pop();
    }

    dp[i] = sum;
    dp1[i] = pq.front();

    res = max(res, dp[i]);
  }


  while (q--) {
    int x, y;
    cin >> x >> y;

    array<int, 2> tmp{y, LLONG_MIN};
    auto it = lower_bound(a.begin(), a.end(), tmp) - a.begin();

    int ans = 0;
    if (it == n || a[it][0] > y) {
      ans += x;
    }

    ans 
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
