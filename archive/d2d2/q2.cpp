// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
#include <bits/stdc++.h>

using namespace std;

#define int long long

void lpsFind(string &w, vector<int> &a) {
  int pre = 0, suff = 1;
  while (suff < w.size()) {
    if (w[pre] == w[suff]) {
      a[suff] = pre + 1;
      pre++, suff++;
    }
    else {
      if (pre == 0) {
        a[suff] = 0;
        suff++;
      }
      else {
        pre = a[pre - 1];
      }
    }
  }
}

void solve() {
  string w, t;
  cin >> w >> t;
  vector<int> lps(w.size());
  lpsFind(w, lps);
  int ans = 0, pre = 0, suff = 0;
  while (suff < t.size()) {
    if (w[pre] == t[suff]) {
      pre++, suff++;
    }
    else {
      if (pre == 0) {
        suff++;
      }
      else {
        pre = lps[pre - 1];
      }
    }
    if (pre == w.size()) {
      ans++;
      pre = lps[pre - 1];
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
