class dsu_skip {
 public:
  int n, cnt;
  bool cyc;
  vector<int> p, nx, pv;

  dsu_skip(int _n, bool _cyc = false) : n(_n), cnt(_n), cyc(_cyc) {
    p.resize(n);
    nx.resize(n);
    pv.resize(n);
    iota(p.begin(), p.end(), 0);
    iota(nx.begin(), nx.end(), 0);
    iota(pv.begin(), pv.end(), 0);
  }

  inline int get(int x) { return (x == p[x] ? x : (p[x] = get(p[x]))); }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }

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