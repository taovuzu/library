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
  int n;
  cin >> n;
  vector<int> ans;

  if (n % 2 == 1) {
    ans.push_back(n);
    ans.push_back(n);
    ans.push_back(2);
    ans.push_back(n);
    ans.push_back(1);
    ans.push_back(1);
    ans.push_back(2);
    ans.push_back(1);
    ans.push_back(2);
    ans.push_back(2);
    ans.push_back(1);
    ans.push_back(n);
    n--;
  }
  else {
    ans.push_back(2);
    ans.push_back(1);
    ans.push_back(1);
    ans.push_back(2);
    ans.push_back(1);
    ans.push_back(2);
    ans.push_back(2);
    ans.push_back(1);
  }

  for (int i = 3; i <= n; i += 2) {
    ans.push_back(i + 1);
    ans.push_back(i);
    ans.push_back(i);
    ans.push_back(i + 1);
    ans.push_back(i);
    ans.push_back(i + 1);
    ans.push_back(i + 1);
    ans.push_back(i);
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " \n"[i == ans.size() - 1];
  }
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
