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

int n, k, d;
void rec(int idx, vector<int> &p, vector<vector<int>> &a) {
  if (a.size() >= n) return;
  if (idx >= d) {
    a.push_back(p);
    return;
  }
  for (int i = 1; i <= k && a.size() < n; i++) {
    p.push_back(i);
    rec(idx + 1, p, a);
    p.pop_back();
  }
}

void solve() {
  cin >> n >> k >> d;
  int tmp = 1;
  for (int i = 0; i < d; i++) {
    tmp *= k;
    if (tmp > n) break;
  }
  if (n > tmp) {
    cout << -1;
  }
  else {
    vector<vector<int>> a;
    vector<int> p;
    rec(0, p, a);
    for (int i = 0; i < d; i++) {
      for (int j = 0; j < n; j++) {
        cout << a[j][i] << " \n"[j == n - 1];
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
