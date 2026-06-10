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
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  
  int ans = 0, i = 0, j = n - 1, curr = 0;
  vector<int> b;
  while (i <= j) {
    if ((curr + a[j]) >= x) {
      curr += a[j];
      ans += a[j];
      b.push_back(a[j]);
      j--;
    }
    else {
      if (curr + a[i] >= x) {
        ans += a[i];
      }
      curr += a[i];
      b.push_back(a[i]);
      i++;
    }
    curr %= x;
  }

  cout << ans << "\n";
  for (int h = 0; h < n; h++) {
    cout << b[h] << " \n"[h == n - 1];
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
