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
  vector<int> seg;
  vector<int> &a;

  segtree(int n_, vector<int>& arr) : n(n_), a(arr) {
    int size = 1;
    while (size < 2 * n) size <<= 1;
    seg.resize(size, LLONG_MAX);
    build(0, n - 1, 0);
  }

  void build(int l, int r, int index) {
    if (l == r) {
      seg[index] = a[l];
      return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * index + 1);
    build(mid + 1, r, 2 * index + 2);
    seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
  }

  void update(int l, int r, int index, int pos, int val) {
    if (l == r) {
      a[pos] = val;
      seg[index] = val;
      return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid) update(l, mid, 2 * index + 1, pos, val);
    else update(mid + 1, r, 2 * index + 2, pos, val);
    seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
  }

  int query(int l, int r, int index, int ll, int rr) {
    if (l > rr || r < ll) return LLONG_MAX;
    if (ll <= l && r <= rr ) return seg[index];
    int mid = (l + r) / 2;
    int left = query(l, mid, 2 * index + 1, ll, rr);
    int right = query(mid + 1, r, 2 * index + 2, ll, rr);
    return min(left, right);
  }
};


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  segtree sx(n, a);
  while(q--) {
    string s, temp = "";
    cin >> s;
    vector<int> b;
    for (int i = 6; i < s.size() - 1; i++) {
      if(s[i] != ',') {
        temp += s[i];
      }
      else {
        b.push_back(stoi(temp) - 1);
        temp = "";
      }
    }
    if (!temp.empty()) b.push_back(stoi(temp) - 1);

    if (s[0] == 'q') {
      cout << sx.query(0, n - 1, 0, b[0], b[1]) << "\n";
    }
    else {
      int x = a[b[0]];
      for (int i = 0; i < b.size() - 1; i++) {
        sx.update(0, n - 1, 0, b[i], a[b[i + 1]]);
      }
      sx.update(0, n - 1, 0, b.back(), x);
    }
  }


  return 0;
}
