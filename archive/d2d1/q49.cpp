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

class segtree{
  public:
  struct node {
    int sum;
    int left;
    int right;
    int best;
  };

  int n;
  vector<int> a;
  vector<node> seg;
  segtree(int n_, vector<int>& arr) {
    n = n_;
    a = arr;
    seg.resize(4 * n);
    build(0, n - 1, 0);
  }

  void build(int l, int r, int index) {
    if (l == r) {
      seg[index] = {a[l], a[l], a[l], a[l]};
      return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * index + 1);
    build(mid + 1, r, 2 * index + 2);
    int sum = seg[2 * index + 1].sum + seg[2 * index + 2].sum;
    int left = max({seg[2 * index + 1].left, seg[2 * index + 1].sum + seg[2 * index + 2].left});
    int right = max({seg[2 * index + 2].right, seg[2 * index + 2].sum + seg[2 * index + 1].right});
    int best = max({seg[2 * index + 1].best, seg[2 * index + 2].best, seg[2 * index + 1].right + seg[2 * index + 2].left});
    seg[index] = {sum, left, right, best};
  }

  node query(int l, int r, int index, int ll, int rr) {
    if (rr < l || ll > r) return {0, MAXI, MAXI, MAXI};
    if (ll <= l && r <= rr) return seg[index];
    int mid = (l + r) / 2;
    node x = query(l, mid, 2 * index + 1, ll, rr);
    node y = query(mid + 1, r, 2 * index + 2, ll, rr);
    int sum = x.sum + y.sum;
    int left = max({x.left, x.sum + y.left});
    int right = max({y.right, y.sum + x.right});
    int best = max({x.best, y.best, x.right + y.left});
    return {sum, left, right, best};
  }

  int make_query(int l, int r) {
    return query(0, n - 1, 0, l, r).best;
  }

};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, q, x, y;
  cin >> n;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  segtree sx(n, a);
  
  cin >> q;
  while (q--) {
    cin >> x >> y;
    cout << sx.make_query(x - 1, y - 1) << "\n";
  }

  return 0;
}