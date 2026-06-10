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
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[a[i]] = 1;
  }
  int i = 1, j = n;
  while (i <= n) {
    if (a[i] == 0) {
      while (b[j]) j--;
      a[i] = j;
      j--;
    }
    i++;
  }
  pr(a);
  int mini = -1, maxi = -1;
  for (i = 1; i <= n; i++) {
    if (a[i] != i) {
      if (mini == -1) {
        mini = i, maxi = i;
      }
      else {
        maxi = i;
      }
    }
  }
  cout << (maxi - mini + (maxi != mini)) << "\n";
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
