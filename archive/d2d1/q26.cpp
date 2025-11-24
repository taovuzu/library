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
  string &s;
  vector<array<int, 2>> seg;

  segtree(int n_, string& s1) : n(n_), s(s1) {
    seg.resize(4 * n);
    build(0, n - 1, 0);
  }

  void merge(int index) {
    seg[index][0] = max(0LL, seg[2 * index + 1][0] - seg[2 * index + 2][1]) + seg[2 * index + 2][0];
    seg[index][1] = max(0LL, seg[2 * index + 2][1] - seg[2 * index + 1][0]) + seg[2 * index + 1][1];
  }

  void build(int l, int r, int index) {
    if (l == r) {
      seg[index][0] = s[l] == '(';
      seg[index][1] = s[l] == ')';
      return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, (index << 1) + 1);
    build(mid + 1, r, (index << 1) + 2);
    merge(index);
  }

  void update(int l, int r, int index, int qpos) {
    if (qpos < l || qpos > r) return;
    if (l == r) {
      s[l] = s[l] == '(' ? ')' : '(';
      seg[index] = {s[l] == '(', s[l] == ')'};
      return;
    }
    int mid = (l + r) >> 1;
    update(l, mid, (index << 1) + 1, qpos);
    update(mid + 1, r, (index << 1) + 2, qpos);
    merge(index);
  }

  string query() {
    if (seg[0][0] == 0 && seg[0][1] == 0) return "YES";
    else return "NO";
  }

};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int tt = 1; tt <= 10; tt++ ) {
    cout << "Test" << " " << tt << ":" << "\n";
    int n, q, x;
    string s;
    cin >> n >> s;

    segtree sx(n, s);
    cin >> q;
    while (q--) {
      cin >> x;
      if (x > 0) {
        sx.update(0, n - 1, 0, x - 1);
      }
      else {
        cout << sx.query() << "\n";
      }
    }
  }

  return 0;
}
