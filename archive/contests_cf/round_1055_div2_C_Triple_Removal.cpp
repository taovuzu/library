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

template <typename Node, typename Update>
struct segtree {
  vector<Node> tree;
  vector<long long> arr;  // type may change
  int n;
  int s;
  segtree(int a_len, vector<long long> &a) {  // change if type updated
    arr = a;
    n = a_len;
    s = 1;
    while (s < n) {
      s = s << 1;
    }
    tree.resize(2 * s - 1);
    fill(tree.begin(), tree.end(), Node());
    build(0, n - 1, 0);
  }
  void build(int l, int r, int index)  // Never change this
  {
    if (l == r) {
      tree[index] = Node(arr[l]);
      return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * index + 1);
    build(mid + 1, r, 2 * index + 2);
    tree[index].merge(tree[2 * index + 1], tree[2 * index + 2]);
  }
  void update(int l, int r, int index, int query_index,
              Update &u)  // Never Change this
  {
    if (l == r) {
      u.apply(tree[index]);
      return;
    }
    int mid = (l + r) / 2;
    if (query_index <= mid)
      update(l, mid, 2 * index + 1, query_index, u);
    else
      update(mid + 1, r, 2 * index + 2, query_index, u);
    tree[index].merge(tree[2 * index + 1], tree[2 * index + 2]);
  }
  Node query(int l, int r, int index, int left,
             int right) {  // Never change this
    if (l > right || r < left) return Node();
    if (l >= left && r <= right) return tree[index];
    int mid = (l + r) / 2;
    Node lres = query(l, mid, 2 * index + 1, left, right);
    Node rres = query(mid + 1, r, 2 * index + 2, left, right);
    Node ans;
    ans.merge(lres, rres);
    return ans;
  }
  void make_update(int index,
                   long long val) {   // pass in as many parameters as required
    Update new_update = Update(val);  // may change
    update(0, n - 1, 0, index, new_update);
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
    val = l.val | r.val;            // may change
  }
};

struct Update1 {
  long long val;           // may change
  Update1(long long p1) {  // Actual Update
    val = p1;              // may change
  }
  void apply(Node1 &a) {  // apply update to given node
    a.val = val;          // may change
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n), b(n), preZero(n), preOne(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) b[i] = a[i] == a[i - 1];
    if (i) {
      preOne[i] += preOne[i - 1];
      preZero[i] += preZero[i - 1];
    }
    if (a[i]) preOne[i]++;
    else preZero[i]++;
  }
  segtree<Node1, Update1> sx(n, b);
  while(q--) {
    int l, r;
    cin >> l >> r;
    r--, l--;
    int x = preZero[r] - (l ? preZero[l - 1] : 0), y = preOne[r] - (l ? preOne[l - 1] : 0);
    if (x % 3 != 0 || y % 3 != 0) {
      cout << -1 << "\n";
      continue;
    }
    if (sx.make_query(l + 1, r).val) {
      cout << (r - l + 1) / 3 << "\n";
    }
    else {
      cout << (r - l + 1) / 3 + 1 << "\n";
    }
  }
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
