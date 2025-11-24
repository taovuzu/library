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
  int n, size = 1;
  vector<int> seg;
  vector<int>& a;

  segtree(int n_, vector<int> &arr) : n(n_), a(arr){
    while (size < 2 * n) size <<= 1;
    seg.resize(size);
    build(0, n - 1, 0);
  }

  void build(int start, int end, int index) {
    if (start == end) {
      seg[index] = a[start];
      return;
    }
    int mid = (start + end) / 2;
    build(start, mid, 2 * index + 1);
    build(mid + 1, end, 2 * index + 2);
    seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);
  }

  void update(int start, int end, int index, int pos, int val) {
    if (start == end) {
      a[pos] = val;
      seg[index] = a[pos];
      return;
    }
    int mid = (start + end) / 2;
    if (pos <= mid) update(start, mid, 2 * index + 1, pos, val);
    else update(mid + 1, end, 2 * index + 2, pos, val);
    seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);
  }

  int query(int start, int end, int index, int l, int r) {
    if (r < start || l > end) return 0;
    if (l <= start && r >= end) return seg[index];
    int mid = (start + end) / 2;
    int x = query(start, mid, 2 * index + 1, l, r);
    int y = query(mid + 1, end, 2 * index + 2, l, r);
    return max(x, y);
  }

  int make_query(int left, int right) {
    return query(0, n - 1, 0, left, right);
  }

  void make_update(int pos, int val) {
    update(0, n - 1, 0, pos, val);
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m, q;
  cin >> n >> m;

  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }

  cin >> q;
  segtree sx(m, a);

  while (q--) {
    int xs, ys, xf, yf, k;
    cin >> xs >> ys >> xf >> yf >> k;

    if ((abs(xs - xf) % k != 0) || (abs(ys - yf) % k != 0)) {
      cout << "NO\n";
      continue;
    }

    int top = xs + ((n - xs) / k) * k;
    int l = min(ys, yf) - 1, r = max(ys, yf) - 1;
    int mx = sx.make_query(l, r);

    if (mx < top) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
