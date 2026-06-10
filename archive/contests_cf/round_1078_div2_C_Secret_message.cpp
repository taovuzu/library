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
  int n, k;
  cin >> n >> k;

  vector freq(n, vector<int> (26));

  vector<string> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    for (int j = 0; j < n; j++) {
      int x = a[i][j] - 'a';
      freq[j][x] = 1;
    }
  }

  string ans = a[0];
  for (int i = 1; i < n; i++) {
    if (n % i != 0) continue;
    bool flag = true;
    string s = "";
    for (int i_ = 0; i_ < i; i_++) {
      vector<int> b(26, 1);
      for (int h = 0; h < 26; h++) {
        for (int j = i_; j < n; j += i) {
          b[h] &= freq[j][h];
          if (b[h] == 0) break;
        }
        if (b[h]) {
          s += ('a' + h);
          break;
        }
      }
      if (s.size() == i_) {
        flag = false;
        break;
      }
    }
    if (flag) {
      ans = "";
      while (ans.size() < n) {
        ans += s;
      }
      break;
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
