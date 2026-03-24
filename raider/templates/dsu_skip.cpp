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