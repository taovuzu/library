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

int nck(int n, int k) {
  if (k > n - k) k = n - k;
  __int128 res = 1;
  for (int i = 1; i <= k; i++) {
    res = res * (n - k + i) / i;
  }
  return res;
}

void solve() {
  string s;
  getline(cin, s);
  string tmp = "";
  vector<int> a;
  for (int i  = 0; i < s.size(); i++) {
    if (s[i] == '{') continue;
    else if (s[i] == ',' || s[i] == '{' || s[i] == '}') {
      int num = stoi(tmp);
      a.push_back(num);
      tmp = "";
    }
    else tmp += s[i];
  }

  int ans = 1;
  for (int i = 0; i < a.size(); i++) {
    int l = a[i] << 1, r = ((a[i] << 1) | 1), lc = 0, rc = 0;
    for (int j = 0; j < a.size(); j++) {
      int x = a[j];
      while (x > r) x >>= 1;
      if (x == r) rc++;
      else if (x == l) lc++;
    }
    ans *= nck(rc + lc, lc);
  }
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}