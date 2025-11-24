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

void solve() {
  int n;
  string s;
  cin >> n >> s;
  vector<vector<int>> pre(26, vector<int> (s.size() + 1));
  for (int i = 0; i < s.size(); i++) {
    pre[s[i] - 'A'][i]++;
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 1; j < s.size(); j++) {
      pre[i][j] += pre[i][j - 1];
    }
  }

  while (n--) {
    int i = 0, j = 0;
    string s1;
    cin >> s1;
    while (i < s.size() && j < s1.size()) {
      int num = 0, ch;
      while (j < s1.size() && s1[j] >= '0' && s1[j] <= '9') {
        num = num * 10 + (s1[j] - '0');
        j++;
      }
      ch = s1[j] - 'A';
      int cnt = (i - 1 >= 0 ? pre[ch][i - 1] : 0) + num;
      i = lower_bound(pre[ch].begin(), pre[ch].end(), cnt) - pre[ch].begin();
      i++;
      if (i < s.size() || pre[ch][s.size() - 1] >= cnt) j++;
    }
    cout << (i >= s.size() && j < s1.size() ? "NO" : "YES")  << "\n";
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
