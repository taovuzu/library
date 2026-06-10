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

int n;
vector<int> a(100100);

bool isValid(vector<int> &b) {
  int left = 0, right = accumulate(b.begin(), b.end(), 0LL);
  for (int i = 0; i < n; i++) {
    if (!b[i]) left++;
    if (left + right != a[i]) return false;
    if (b[i]) right--;
  }
  return true;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n), c(n);
  b[0] = 0, c[0] = 1;
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] == a[i]) b[i + 1] = (b[i] == 0 ? 1 : 0);
    else b[i + 1] = b[i];
    if (a[i + 1] == a[i]) c[i + 1] = (c[i] == 0 ? 1 : 0);
    else c[i + 1] = c[i];
  }
  int ans = isValid(b) + isValid(c);
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
