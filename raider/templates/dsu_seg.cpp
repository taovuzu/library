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