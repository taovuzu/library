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
  int sum = 0;
  priority_queue<int> pq, pq1;
  
  for (int i = 0; i < n; i++) {
    int x; 
    cin >> x;
    sum += x;
    if (i % 2 == 0) pq.push(x);
    else pq1.push(x);
  }

  bool flag = false, flag1 = false;

  pr(sum, pq, pq1);

  while (m--) {
    int x; 
    cin >> x;
    if (x % 2 == 1) {
      if (!pq.empty()) {
        sum -= flag ? max(0LL, pq.top()) : pq.top();
        flag = true;
        pq.pop();
      }
    }
    else {
      if (!pq1.empty()) {
        sum -= flag1 ? max(0LL, pq1.top()) : pq1.top();
        flag1 = true;
        pq1.pop();
      }
    }
    pr(x, pq, pq1, sum);
  }

  cout << sum << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt = 1;
  cin >> tt;

  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
