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

  multiset<int> xt;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> b(m), c(m), d;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    xt.insert(x);
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> c[i];
    if (c[i]) {
      pq.push({b[i], c[i]});
    }
    else {
      d.push_back(b[i]);
    }
  }

  sort(d.rbegin(), d.rend());

  int ans = 0;
  while (!pq.empty()) {
    auto [x, y] = pq.top();
    pq.pop();
    auto it = xt.lower_bound(x);
    if (it == xt.end()) {
      break;
    }
    int tmp = *it;
    xt.erase(it);
    xt.insert(max(tmp, y));
    ans++;
  }


  for (int i = 0; i < d.size(); i++) {
    if (!xt.empty() && d[i] <= *prev(xt.end())) {
      xt.erase(prev(xt.end()));
      ans++;
    }
  }

  cout << ans << "\n";

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
