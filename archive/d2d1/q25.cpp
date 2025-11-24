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

struct lazySegtree {
  int n;
  vector<int> seg;
  // lazyOp: -1 = no-op, 0 = set to 0 (E), 1 = set to 1 (F), 2 = invert (I)
  vector<int> lazyOp;

  lazySegtree(int _n, const vector<int>& a) : n(_n) {
    seg.assign(4 * n, 0);
    lazyOp.assign(4 * n, -1);
    build(1, 0, n - 1, a);
  }

  void build(int node, int l, int r, const vector<int>& a) {
    if (l == r) {
      seg[node] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(2 * node, l, mid, a);
    build(2 * node + 1, mid + 1, r, a);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
  }

  // apply operation 'op' to this node
  void apply(int node, int l, int r, int op) {
    if (op == 0 || op == 1) {
      // set all to 0 or 1
      seg[node] = (r - l + 1) * op;
      lazyOp[node] = op;
    } else if (op == 2) {
      // invert
      seg[node] = (r - l + 1) - seg[node];
      if (lazyOp[node] == -1) {
        lazyOp[node] = 2;
      } else if (lazyOp[node] == 2) {
        // invert + invert = no-op
        lazyOp[node] = -1;
      } else {
        // invert over a set: flip the set
        lazyOp[node] = 1 - lazyOp[node];
      }
    }
  }

  void push(int node, int l, int r) {
    int op = lazyOp[node];
    if (op == -1 || l == r) return;
    int mid = (l + r) >> 1;
    apply(2 * node, l, mid, op);
    apply(2 * node + 1, mid + 1, r, op);
    lazyOp[node] = -1;
  }

  void update(int node, int l, int r, int ql, int qr, int op) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
      apply(node, l, r, op);
      return;
    }
    push(node, l, r);
    int mid = (l + r) >> 1;
    update(2 * node, l, mid, ql, qr, op);
    update(2 * node + 1, mid + 1, r, ql, qr, op);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
  }

  int query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) {
      return seg[node];
    }
    push(node, l, r);
    int mid = (l + r) >> 1;
    return query(2 * node, l, mid, ql, qr) +
           query(2 * node + 1, mid + 1, r, ql, qr);
  }

  void update(int l, int r, int op) { update(1, 0, n - 1, l, r, op); }
  int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    cout << "Case " << tc << ":\n";

    int M;
    cin >> M;
    vector<int> pirates;
    pirates.reserve(1024000);

    while (M--) {
      int times;
      string block;
      cin >> times >> block;
      for (int t = 0; t < times; t++) {
        for (char c : block) {
          pirates.push_back(c == '1' ? 1 : 0);
        }
      }
    }

    int n = pirates.size();
    lazySegtree st(n, pirates);

    int Q;
    cin >> Q;
    int qcnt = 1;
    while (Q--) {
      char cmd;
      int a, b;
      cin >> cmd >> a >> b;
      if (cmd == 'F') {
        st.update(a, b, 1);
      } else if (cmd == 'E') {
        st.update(a, b, 0);
      } else if (cmd == 'I') {
        st.update(a, b, 2);
      } else if (cmd == 'S') {
        int ans = st.query(a, b);
        cout << "Q" << qcnt++ << ": " << ans << "\n";
      }
    }
  }

  return 0;
}
