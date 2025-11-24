// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति।
// उखँ थाशवफुलपवँ पप फवसजडिऊँ यि लेटीप्चँ यि प फुलेंवळेद्ल्
// भाशवँ उखँ चतुर्थः प्रश्नः ईवफवुल हवराधपँ नत्वूँ पलफपवुलँ वठउव्षँ प यखयबोप
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

class segtree {
 public:
  struct node {
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!
    ... a = ...;

    void apply(int l, int r, ... v) {
      ...
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    ...
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    // push from x into (x + 1) and z
    ...
/*
    if (tree[x].add != 0) {
      tree[x + 1].apply(l, y, tree[x].add);
      tree[z].apply(y + 1, r, tree[x].add);
      tree[x].add = 0;
    }
*/
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  int n;
  vector<node> tree;

  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }

  template <typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }

  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }

  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }

  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }

  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename M>
  segtree(const vector<M> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }

  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }

  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }

  template <typename... M>
  void modify(int ll, int rr, const M&... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }

  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once

  int find_first(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }

  int find_last(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};

template <typename T>
vector<T> dijkstra(const graph<T> &g, int start) {
  assert(0 <= start && start < g.n);
  vector<T> dist(g.n, numeric_limits<T>::max());
  dist[start] = 0;
  set<pair<T, int>> s;
  s.emplace(dist[start], start);
  while (!s.empty()) {
    int i = s.begin()->second;
    s.erase(s.begin());
    for (int id : g.g[i]) {
      auto &e = g.edges[id];
      int to = e.from ^ e.to ^ i;
      if (dist[i] + e.cost < dist[to]) {
        s.erase({dist[to], to});
        dist[to] = dist[i] + e.cost;
        s.emplace(dist[to], to);
      }
    }
  }
  return dist;
  // returns numeric_limits<T>::max() if there's no path
}

template <typename T>
class dfs_undigraph : public undigraph<T> {
 public:
  using undigraph<T>::edges;
  using undigraph<T>::g;
  using undigraph<T>::n;

  vector<int> pv;
  vector<int> pe;
  vector<int> order;
  vector<int> pos;
  vector<int> end;
  vector<int> sz;
  vector<int> root;
  vector<int> depth;
  vector<int> min_depth;
  vector<T> dist;
  vector<int> was;
  int attempt;

  dfs_undigraph(int _n) : undigraph<T>(_n) {
  }

  void init() {
    pv = vector<int>(n, -1);
    pe = vector<int>(n, -1);
    order.clear();
    pos = vector<int>(n, -1);
    end = vector<int>(n, -1);
    sz = vector<int>(n, 0);
    root = vector<int>(n, -1);
    depth = vector<int>(n, -1);
    min_depth = vector<int>(n, -1);
    dist = vector<T>(n);
    was = vector<int>(n, -1);
    attempt = 0;
  }

  void clear() {
    pv.clear();
    pe.clear();
    order.clear();
    pos.clear();
    end.clear();
    sz.clear();
    root.clear();
    depth.clear();
    min_depth.clear();
    dist.clear();
    was.clear();
  }

 private:
  void do_dfs(int v) {
    was[v] = attempt;
    pos[v] = (int) order.size();
    order.push_back(v);
    sz[v] = 1;
    min_depth[v] = depth[v];
    for (int id : g[v]) {
      if (id == pe[v]) {
        continue;
      }
      auto &e = edges[id];
      int to = e.from ^ e.to ^ v;
      if (was[to] == attempt) {
        min_depth[v] = min(min_depth[v], depth[to]);
        continue;
      }
      depth[to] = depth[v] + 1;
      dist[to] = dist[v] + e.cost;
      pv[to] = v;
      pe[to] = id;
      root[to] = (root[v] != -1 ? root[v] : to);
      do_dfs(to);
      sz[v] += sz[to];
      min_depth[v] = min(min_depth[v], min_depth[to]);
    }
    end[v] = (int) order.size() - 1;
  }

  void do_dfs_from(int v) {
    ++attempt;
    depth[v] = 0;
    dist[v] = T{};
    root[v] = v;
    pv[v] = pe[v] = -1;
    do_dfs(v);
  }

 public:
  void dfs(int v, bool clear_order = true) {
    if (pv.empty()) {
      init();
    } else {
      if (clear_order) {
        order.clear();
      }
    }
    do_dfs_from(v);
  }

  void dfs_all() {
    init();
    for (int v = 0; v < n; v++) {
      if (depth[v] == -1) {
        do_dfs_from(v);
      }
    }
    assert((int) order.size() == n);
  }
};

template <typename Node, typename Update>
struct lazySegtree {
  vector<Node> tree;
  vector<bool> lazy;
  vector<Update> updates;
  vector<long long> arr;  // type may change
  int n;
  int s;
  lazySegtree(int a_len, vector<long long> &a) {  // change if type updated
    arr = a;
    n = a_len;
    s = 1;
    while (s < n) {
      s = s << 1;
    }
    // total nodes in a full binary tree with 's' leaves: 2*s - 1
    tree.resize(2 * s - 1);
    fill(tree.begin(), tree.end(), Node());
    lazy.resize(2 * s - 1);
    fill(lazy.begin(), lazy.end(), false);
    updates.resize(2 * s - 1);
    fill(updates.begin(), updates.end(), Update());
    build(0, n - 1, 0);
  }
  void build(int start, int end, int index) {  // Never change this
    if (start == end) {
      tree[index] = Node(arr[start]);
      return;
    }
    int mid = (start + end) / 2;
    build(start, mid, 2 * index + 1);
    build(mid + 1, end, 2 * index + 2);
    tree[index].merge(tree[2 * index + 1], tree[2 * index + 2]);
  }
  void pushdown(int index, int start, int end) {  // Never change this
    if (lazy[index]) {
      int mid = (start + end) / 2;
      apply(2 * index + 1, start, mid, updates[index]);
      apply(2 * index + 2, mid + 1, end, updates[index]);
      updates[index] = Update();
      lazy[index] = false;
    }
  }
  void apply(int index, int start, int end, Update &u) {
    if (start != end) {
      lazy[index] = true;
      updates[index].combine(u, start, end);
    }
    u.apply(tree[index], start, end);
  }
  void update(int start, int end, int index, int left, int right,
              Update &u) {  // Never Change this
    if (start > right || end < left) return;
    if (start >= left && end <= right) {
      apply(index, start, end, u);
      return;
    }
    pushdown(index, start, end);
    int mid = (start + end) / 2;
    update(start, mid, 2 * index + 1, left, right, u);
    update(mid + 1, end, 2 * index + 2, left, right, u);
    tree[index].merge(tree[2 * index + 1], tree[2 * index + 2]);
  }
  Node query(int start, int end, int index, int left,
             int right) {  // Never change this
    if (start > right || end < left) return Node();
    if (start >= left && end <= right) {
      pushdown(index, start, end);
      return tree[index];
    }
    pushdown(index, start, end);
    int mid = (start + end) / 2;
    Node l, r, ans;
    l = query(start, mid, 2 * index + 1, left, right);
    r = query(mid + 1, end, 2 * index + 2, left, right);
    ans.merge(l, r);
    return ans;
  }
  void make_update(int left, int right,
                   long long val) {   // pass in as many parameters as required
    Update new_update = Update(val);  // may change
    update(0, n - 1, 0, left, right, new_update);
  }
  Node make_query(int left, int right) {
    return query(0, n - 1, 0, left, right);
  }
};

struct Node1 {
  long long val;  // may change
  Node1() {       // Identity element
    val = 0;      // may change
  }
  Node1(long long p1) {  // Actual Node
    val = p1;            // may change
  }
  void merge(Node1 &l, Node1 &r) {  // Merge two child nodes
    val = l.val + r.val;            // may change
  }
};

struct Update1 {
  long long val;  // may change
  Update1() {     // Identity update
    val = 0;
  }
  Update1(long long val1) {  // Actual Update
    val = val1;
  }
  void apply(Node1 &a, int start, int end) {  // apply update to given node
    a.val = val * (end - start + 1);          // may change
  }
  void combine(Update1 &new_update, int start, int end) {
    val = new_update.val;
  }
};

template <typename T>
class forest : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  forest(int _n) : graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    assert(id < n - 1);
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

class segtree{
  public:
  int n;
  string s;
  vector<array<int, 2>> seg;
  segtree(string &s1) {
    s = s1;
    n = s.size();
    seg.resize(4 * n, {0, 0});
    build(0, n - 1, 0);
  }

  array<int, 2> selecter(array<int, 2> x, array<int, 2> y) {
    int lo = x[0], lc = x[1], ro = y[0], rc = y[1];
    return {max(0LL, lo - rc) + ro, max(0LL, rc - lo) + lc};
  }

  void build(int l, int r, int index) {
    if (l == r) {
      seg[index][0] = s[l] == '(' ? 1 : 0;
      seg[index][1] = s[r] == ')' ? 1 : 0;
      return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * index + 1);
    build(mid + 1, r, 2 * index + 2);
    seg[index] = selecter(seg[2 * index + 1], seg[2 * index + 2]);
  }

  array<int, 2> query(int l, int r, int index, int ll, int rr) {
    if (l > rr || ll > r) return {0, 0};
    if (ll <= l && r <= rr) return seg[index];
    int mid = (l + r) / 2;
    return selecter(query(l, mid, 2 * index + 1, ll, rr), query(mid + 1, r, 2 * index + 2, ll, rr));
  }

};


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  int q, x, y;

  cin >> s >> q;

  segtree sx(s);
  while (q--) {
    cin >> x >> y;
    array<int, 2> a = sx.query(0, s.size() - 1, 0, x - 1, y - 1);
    int ans = y - x + 1 - a[0] - a[1];
    cout << ans << "\n";
  }

  return 0;
}
