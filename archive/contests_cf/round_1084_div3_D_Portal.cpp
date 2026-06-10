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
  int n, x, y;
  cin >> n >> x >> y;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  deque<int> dq;
  int mini = LLONG_MAX;

  for (int i = x; i < y; i++) {
    dq.push_back(a[i]);
    mini = min(a[i], mini);
  }

  while (!dq.empty() && dq.front() != mini) {
    dq.push_back(dq.front());
    dq.pop_front();
  }

  vector<int> b(a.begin(), a.begin() + x);
  for (int i = y; i < n; i++) {
    b.push_back(a[i]);
  }

  vector<int> ans;
  int i = 0;

  while(i < b.size() && !dq.empty() && dq.front() > b[i]) {
    ans.push_back(b[i++]);
  }
  while (!dq.empty()) {
    ans.push_back(dq.front());
    dq.pop_front();
  }
  while (i < b.size()) {
    ans.push_back(b[i++]);
  }

  for (int j = 0; j < n; j++) {
    cout << ans[j] << " \n"[j == n - 1];
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
