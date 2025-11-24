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
    if (left > right) {
      update(0, n - 1, 0, left, n - 1, new_update);
      update(0, n - 1, 0, 0, right, new_update);
    }
    else update(0, n - 1, 0, left, right, new_update);
  }
  Node make_query(int left, int right) {
    if (left > right) {
      return Node(min(query(0, n - 1, 0, left, n - 1).val, query(0, n - 1, 0, 0, right).val));
    }
    return query(0, n - 1, 0, left, right);
  }
};

struct Node1 {
  long long val;  // may change
  Node1() {       // Identity element
    val = LLONG_MAX;      // may change
  }
  Node1(long long p1) {  // Actual Node
    val = p1;            // may change
  }
  void merge(Node1 &l, Node1 &r) {  // Merge two child nodes
    val = min(l.val , r.val);            // may change
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
    a.val += val;          // may change
  }
  void combine(Update1 &new_update, int start, int end) {
    val += new_update.val;
  }
};


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, q;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  lazySegtree<Node1, Update1> sx(n, a);

  cin >> q;
  cin.ignore();
  while (q--) {
    string s;
    int x, y, z;
    getline(cin, s);
    istringstream iss(s);
    iss >> x >> y;
    if (iss >> z) {
      sx.make_update(x, y, z);
    }
    else {
      cout << sx.make_query(x, y).val << "\n";
    }
  }

  return 0;
}
