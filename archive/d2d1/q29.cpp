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

class segtree{
  public:
  int n;
  vector<int> a;
  vector<array<int, 2>> seg;
  segtree(int n_, vector<int> &arr) {
    n = n_;
    a = arr;
    seg.resize(4 * n);
    build(0, n - 1, 0);
  }

  array<int, 2> selecter(array<int, 2> x, array<int, 2> y) {
    int mini = x[0], mini1 = x[1], mini2 = y[0], mini3 = y[1];

    array<int, 2> result;
    if (mini >= mini2) {
      result[0] = mini;
      result[1] = max(mini1, mini2);
    } else {
      result[0] = mini2;
      result[1] = max(mini, mini3);
    }
    return result;
  }

  void merger(int index) {
    seg[index] = selecter(seg[2 * index + 1], seg[2 * index + 2]);
  }

  void build(int l, int r, int index) {
    if (l == r) {
      seg[index] = {a[l], LLONG_MIN};
      return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * index + 1);
    build(mid + 1, r, 2 * index + 2);
    merger(index);
  }

  void update(int l, int r, int index, int qpos, int qval) {
    if (l == r) {
      a[l] =  qval;
      seg[index] = {a[l], LLONG_MIN};
      return;
    }
    int mid = (l + r) / 2;
    if (qpos <= mid) update(l, mid, 2 * index + 1, qpos, qval);
    else update(mid + 1, r, 2 * index + 2, qpos, qval);
    merger(index);
  }

  array<int, 2> query(int l, int r, int index, int ll, int rr) {
    if (l > rr || r < ll) return {LLONG_MIN, LLONG_MIN};
    if (ll <= l && r <= rr) return seg[index];
    int mid = (l + r) / 2;
    return selecter(query(l, mid, 2 * index + 1, ll, rr), query(mid + 1, r, 2 * index + 2, ll, rr));
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, q, x, y;
  char ch;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  segtree sx(n, a);
  cin >> q;
  while (q--) {
    cin >> ch >> x >> y;
    if (ch == 'U') {
      sx.update(0, n - 1, 0, x - 1, y);
    }
    else {
      array<int, 2> ans = sx.query(0, n - 1, 0, x - 1, y - 1);
      cout << ans[0] + ans[1] << "\n";
    }
  }

  return 0;
}
