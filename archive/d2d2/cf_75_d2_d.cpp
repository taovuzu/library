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

int n, m;
vector<vector<int>> b(55), d(55);
vector<int> a(300300);

void kdn(int k) {
  int r_max = LLONG_MIN, l_max = LLONG_MIN, max_sum = LLONG_MIN, curr = 0, r_sum = 0, l_sum = 0;
  for (int i = 0; i < b[k].size(); i++) {
    l_sum += b[k][i];
    r_sum += b[k][b[k].size() - 1 - i];
    l_max = max(l_sum, l_max);
    r_max = max(r_max, r_sum);
    curr += b[k][i];
    max_sum = max(curr, max_sum);
    if (curr < 0) curr = 0;
  }
  d[k] = {l_max, r_max, max_sum, r_sum};
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int l, x;
    cin >> l;
    for (int j = 0; j < l; j++)  {
      cin >> x;
      b[i].push_back(x);
    }
    kdn(i);
  }
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  int ans = LLONG_MIN, curr = 0;
  for (int i = 0; i < m; i++) {
    ans = max({ans, curr + d[a[i] - 1][0], d[a[i] - 1][2]});
    curr = max({d[a[i] - 1][1], curr + d[a[i] - 1][3]});
  }
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
