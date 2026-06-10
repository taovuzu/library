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

void rot(vector<int> &a, int i, int j) {
  reverse(a.begin() + i, a.begin() + j);
  reverse(a.begin() + i, a.begin() + j + 1);
}

void solve() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> a(n);
  int last = -1, curr = -1;;
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
    if (s[i] == '1') {
      if (last == curr && last != -1) {
        cout << "NO" << "\n";
        return;
      }
      if(last != -1) rot(a, last, curr);
      last = -1, curr = -1;
    }
    else {
      if (last == -1) last = i, curr = i;
      else curr = i;
    }
  }
  if (last == curr && last != -1) {
    cout << "NO" << "\n";
    return;
  }
  if (last != -1 && s[n - 1] == '0') rot(a, last, curr);
  cout << "YES" << "\n";
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
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
 