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
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    x ^= a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    y ^= b[i];
  }

  if (x != y) {
    cout << "NO" << "\n";
    return;
  }

  cout << "YES" << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0) {
        cout << (y ^ a[0] ^ b[0]) << " ";
      }
      else if (i == 0) {
        cout << b[j] << " \n"[j == m - 1];
      }
      else if (j == 0) {
        cout << a[i] << " ";
      }
      else {
        cout << 0 << " \n"[j == m - 1];
      }
    }
  }

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
