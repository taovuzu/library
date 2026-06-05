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
#define debarr(b, n) {}
#define debmat(mat, row, col) {}
#endif

class dsu_skip {
 public:
  int n;
  vector<int> nx, pv;

  dsu_skip(int _n) : n(_n){
    nx.resize(n);
    pv.resize(n);
    iota(nx.begin(), nx.end(), 0);
    iota(pv.begin(), pv.end(), 0);
  }

  inline int get_next(int x) {
    if (x >= n) return n;
    return (nx[x] == x ? x : (nx[x] = get_next(nx[x])));
  }

  inline int get_prev(int x) {
    if (x < 0) return -1;
    return (pv[x] == x ? x : (pv[x] = get_prev(pv[x])));
  }

  inline bool mark(int x) {
    if (nx[x] != x) return false;
    nx[x] = get_next(x + 1);
    pv[x] = get_prev(x - 1);
    return true;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<array<int, 2>> b(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = {a[i], i};
  }

  sort(b.rbegin(), b.rend());
  vector<int> ans;
  dsu_skip d(n);

  for (int i = 0; i < n; i++) {
    int x = b[i][0];
    int l = b[i][1], r = b[i][1];
    while (l >= 0 && a[l] >= x) {
      d.mark(l);
      l = d.get_prev(l);
    }
    while (r < n && a[r] >= x) {
      d.mark(r);
      r = d.get_next(r);
    }
    int len = r - l - 1;
    while (ans.size() < len) ans.push_back(x);
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}