// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

void solve() {
  int n, k, p;
  cin >> n >> k >> p;

  vector<int> a(n), o, e;
  int odds = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] & 1) odds++, o.push_back(a[i]);
    else e.push_back(a[i]);
  }

  if (odds < (k - p) || ((k - p - odds) & 1) || (n - odds + (odds - (k - p)) / 2) < p) {
    cout << "NO";
    return;
  }

  cout << "YES" << "\n";

  int i = k - p, j = 0;
  for (; j < p; j++) {
    if (j == p - 1) {
      vector<int> tmp;
      while (j < e.size()) tmp.push_back(e[j++]);
      while (i < o.size()) tmp.push_back(o[i++]);
      cout << tmp.size();
      for (auto x : tmp) cout << " " << x;
      cout << "\n";
    }
    else {
      if (j < e.size()) cout << "1 " << e[j] << "\n";
      else {
        cout << "2 " << o[i++] << " " << o[i++] << "\n";
      }
    }
  }

  for (int i_ = 0; i_ < k - p; i_++) {
    if (i_ == k - p - 1) {
      vector<int> tmp;
      tmp.push_back(o[k - p - 1]);
      while (j < e.size()) tmp.push_back(e[j++]);
      while (i < o.size()) tmp.push_back(o[i++]);
      cout << tmp.size();
      for (auto x : tmp) cout << " " << x;
      cout << "\n";
    }
    else {
      cout << "1 " << o[i_] << "\n";
    }
  }

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
