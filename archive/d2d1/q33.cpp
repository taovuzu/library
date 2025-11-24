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
struct segtree {
  vector<Node> tree;
  vector<long long> arr;  // type may change
  int n;
  int s;
  segtree(int a_len) {  // change if type updated
    n = a_len;
    s = 1;
    while (s < n) {
      s = s << 1;
    }
    tree.resize(2 * s - 1);
    fill(tree.begin(), tree.end(), Node());
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
    val = 1;            // may change
  }
  void merge(Node1 &l, Node1 &r) {  // Merge two child nodes
    val = l.val + r.val;            // may change
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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector<int> a(n), b(n);
  set<int> xt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    xt.insert(a[i]);
  }

  int cnt = 0;
  map<int, int> mp;
  for (auto it : xt) {
    mp[it] = cnt++;
  }

  segtree<Node1, Update1> sx(n), sx1(n);
  for (int i = 0; i < n; i++) {
    b[i] = sx.make_query(mp[a[i]], n - 1).val;
    sx.make_update(mp[a[i]], 1);
  }

  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans += b[i] * sx1.make_query(0, mp[a[i]]).val;
    sx1.make_update(mp[a[i]], 1);
  }

  cout << ans;

  return 0;
}
