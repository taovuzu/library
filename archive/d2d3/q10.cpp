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

class dsu_seg {
 public:
  struct data {
    int mn;
    int mx;
    int sum;

    inline void merge(const data& other) {
      mn = min(mn, other.mn);
      mx = max(mx, other.mx);
      sum += other.sum;
    }
  };

  int n, cyc;
  vector<int> p, nx, pv;
  int comp_cnt; 
  int cnt; 
  vector<int> sz;
  vector<data> d;
  vector<int> dist;
  vector<bool> ok;

  dsu_seg(int _n, bool _cyc = false) : n(_n), cyc(_cyc), comp_cnt(_n), cnt(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sz.resize(n, 1);

    d.resize(n);
    for (int i = 0; i < n; ++i) {
      d[i] = {i, i, i};
    }

    nx.resize(n);
    iota(nx.begin(), nx.end(), 0);
    pv.resize(n);
    iota(pv.begin(), pv.end(), 0);

    dist.resize(n, 0);
    ok.resize(n, true);
  }

  inline int get(int x) {
    if (p[x] == x) {
      return x;
    }
    int root = get(p[x]);
    dist[x] += dist[p[x]];
    return p[x] = root;
  }

  inline bool unite(int x, int y) { return unite(x, y, 1); }

  inline bool unite(int x, int y, int w) {
    int rootX = get(x);
    int rootY = get(y);

    if (rootX == rootY) {
      if (ok[rootX] && dist[y] - dist[x] != w) {
        ok[rootX] = false;
      }
      return false;
    }

    if (sz[rootX] < sz[rootY]) {
      swap(rootX, rootY);
      swap(x, y);
      w = -w;
    }

    p[rootY] = rootX;
    sz[rootX] += sz[rootY];
    comp_cnt--;

    d[rootX].merge(d[rootY]);

    dist[rootY] = w + dist[x] - dist[y];
    ok[rootX] = ok[rootX] && ok[rootY];

    return true;
  }

  inline int get_sz(int x) { return sz[get(x)]; }

  inline bool is_con(int x, int y) { return get(x) == get(y); }

  inline int get_comp_cnt() { return comp_cnt; }

  inline const data& get_d(int x) { return d[get(x)]; }

  inline int get_sum(int x) { return d[get(x)].sum; }

  inline int get_min(int x) { return d[get(x)].mn; }

  inline int get_max(int x) { return d[get(x)].mx; }

  inline int get_diff(int x, int y) {
    if (!is_con(x, y)) {
      return INT_MIN;
    }
    return dist[y] - dist[x];
  }

  inline bool is_ok(int x) { return ok[get(x)]; }

  inline int wrap(int x) {
    if (!cyc) return x;
    if (x >= n) return 0;
    if (x < 0) return n - 1;
    return x;
  }

  inline int get_next(int x) {
    if (cnt == 0 || x < 0 || x >= n) {
      return -1;
    }
    return (nx[x] == x ? x : (nx[x] = get_next(nx[x])));
  }

  inline int get_prev(int x) {
    if (cnt == 0 || x < 0 || x >= n) {
      return -1;
    }
    return (pv[x] == x ? x : (pv[x] = get_prev(pv[x])));
  }

  inline bool mark(int x) {
    if (nx[x] != x) {
      return false;
    }
    cnt--;
    nx[x] = get_next(wrap(x + 1));
    pv[x] = get_prev(wrap(x - 1));
    return true;
  }
};

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  dsu_seg d(n + m);

  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    d.unite(x - 1, y - 1 + n);
  }

  cout << (d.get_comp_cnt() - 1) << "\n";
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
