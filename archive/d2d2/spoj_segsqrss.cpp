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

class lazySegtree{
  public:
  int n;
  vector<int> sum, sq, d, lazy;
  lazySegtree(int n_, vector<int> &a) : n(n_) {
    sum.resize(4 * n);
    sq.resize(4 * n);
    d.resize(4 * n);
    lazy.resize(4 * n);
    build(1, 0, n - 1, a);
  }

  void build(int x, int l, int r, vector<int> &a) {
    if (l == r) {
      sum[x] = a[l];
      sq[x] = a[l] * a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(2 * x, l, mid, a);
    build(2 * x + 1, mid + 1, r, a);
    sum[x] = sum[2 * x] + sum[2 * x + 1];
    sq[x] = sq[2 * x] + sq[2 * x + 1];
  }

  void push (int x, int l, int r) {
    if (!lazy[x]) return;
    if (lazy[x] == 1) {
      sq[x] += d[x] * d[x] * (r - l + 1) + 2 * sum[x] * d[x];
      sum[x] += d[x] * (r - l + 1);
    }
    else {
      sum[x] = d[x] * (r - l + 1);
      sq[x] = d[x] * d[x] * (r - l + 1);
    }
    lazy[x] = 0;
    if (l != r) {
      d[2 * x] = d[x];
      d[2 * x + 1] = d[x];
    }
  }

  void update(int x, int t, int val, int l, int r, int ll, int rr) {
   push(x, l, r);
   if (l > rr || r < ll) return;
   if (ll <= l && r <= rr) {
    lazy[x] = t;
    d[x] = val;
    push(x, l, r);
    return;
   }
   int mid = (l + r) >> 1;
   update(2 * x, t, val, l, mid, ll, rr);
   update(2 * x + 1, t, val, mid + 1, r, ll, rr);
   sq[x] = sq[2 * x] + sq[2 * x + 1];
   sum[x] = sum[2 * x] + sum[2 * x + 1];
  }

  int query(int x, int l, int r, int ll, int rr) {
    push(x, l, r);
    if (l > rr || r < ll) return 0;
    if (ll <= l && r <= rr) {
      return sq[x];
    }
    int mid = (l + r) >> 1;
    return query(2 * x, l, mid, ll, rr) + query(2 * x + 1, mid + 1, r, ll, rr);
  }
};

void solve() {
  int n, q, t, st, nd, val;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  lazySegtree sx(n, a);
  while (q--) {
    cin >> t >> st >> nd;
    st--, nd--;
    if (t == 0) {
      cin  >> val;
      sx.update(1, 2, val, 0, n - 1, st, nd);
    }
    else if (t == 1) {
      cin  >> val;
      sx.update(1, 1, val, 0, n - 1, st, nd);
    }
    else {
      cout << sx.query(1, 0, n - 1, st, nd) << "\n";
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    cout << "Case " << t_ << ":" << "\n";
    solve();
  }

  return 0;
}
