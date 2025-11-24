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

const int mod = 1e9 + 7;
int n, x, y, z, ans;

void solve() {
  cin >> x >> y >> z >> n;
  priority_queue<int> pq;
  priority_queue<int, vector<int>, greater<int>> pq1;
  pq1.push(1);
  ans = 1;
  for (int i = 2; i <= n; i++) {
    int tmp = (x * pq1.top() + y * i + z) % mod;
    ans += tmp;
    if (tmp >= pq1.top()) pq1.push(tmp);
    else pq.push(tmp);
    while (pq1.size() > pq.size() + 2) {
      pq.push(pq1.top());
      pq1.pop();
    }
    while (!pq.empty() && pq1.size() < pq.size() + 1) {
      pq1.push(pq.top());
      pq.pop();
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
