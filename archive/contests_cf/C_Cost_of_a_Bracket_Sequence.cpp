// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। ॥
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
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<int> mark(n, -1);
  vector<int> stk;

  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      stk.push_back(i);
    }
    else {
      if (!stk.empty()) {
        mark[stk.back()] = i;
        mark[i] = stk.back();
        stk.pop_back();
      }
    }
  }

  int cnt = 0;
  string ans(n, '0');

  for (int i = 0; i < n && k > 0; i++) {
    if (mark[i] == -1) {
      if (s[i] == '(') cnt++;
      continue;
    }
    if (s[i] == '(') {
      if (cnt == 0) {
        mark[mark[i]] = -1;
        mark[i] = -1;
        ans[i] = '1';
        k--;
      }
    }
    else {
      mark[mark[i]] = -1;
      mark[i] = -1;
      ans[i] = '1';
      k--;
    }
  }

  cout << ans << "\n";

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
