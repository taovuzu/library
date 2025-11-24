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

const int MAXI = -1e5;

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
  long long sum, left, right, best;  // may change
  Node1() {       // Identity element
    sum = 0;
    right = best = left = MAXI;      // may change
  }
  Node1(long long p1) {  // Actual Node
    sum = p1, left = p1, right = p1, best = p1;            // may change
  }
  void merge(Node1 &l, Node1 &r) {  // Merge two child nodes
    sum = l.sum + r.sum;
    left = max({l.left, l.sum + r.left});
    right = max({r.right, r.sum + l.right});
    best = max({l.best, r.best, l.right + r.left});
  }
};

struct Update1 {
  Node1 val;           // may change
  Update1(Node1 p1) {  // Actual Update
    val = p1;              // may change
  }
  void apply(Node1 &a) {  // apply update to given node
    a = val;          // may change
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, q, x, y, t;
  cin >> n;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  segtree<Node1, Update1> sx(n, a);
  
  cin >> q;
  while (q--) {
    cin >> t >> x >> y;
    if (t) cout << sx.make_query(x - 1, y - 1).best << "\n";
    else sx.make_update(x - 1, y);
  }

  return 0;
}