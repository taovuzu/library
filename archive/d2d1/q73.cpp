// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
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

int k, n;

class segtree{
  public:
  int n;
  vector<int> a;
  vector<int> seg;
  segtree(int _n) : n(_n) {
    a.resize(n, k);
    seg.resize(4 * n);
    build(0, n - 1, 0);
  }

  void build(int l, int r, int idx) {
    if (l == r) {
      seg[idx] = k;
      return;
    }
    int m = (l + r) >> 1;
    build(l, m, 2 * idx + 1);
    build(m + 1, r, 2 * idx + 2);
    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
  }

  void update(int qpos, int qval, int l, int r, int idx) {
    if (l == r) {
      a[qpos] -= qval;
      seg[idx] = a[qpos];
      return;
    }
    int m = (l + r) >> 1;
    if (qpos <= m) update(qpos, qval, l, m, 2 * idx + 1);
    else update(qpos, qval, m + 1, r, 2 * idx + 2);
    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
  }

  int query(int l, int r, int idx, int ll, int rr) {
    if (ll <= l && r <= rr) return seg[idx];
    else if (l > rr || ll > r) return LLONG_MIN;
    int m = (l + r) >> 1;
    int left = query(l, m, 2 * idx + 1, ll, rr);
    int right = query(m + 1, r, 2 * idx + 2, ll, rr);
    return max(left, right);
  }

  void make_update(int qpos, int qval) {
    update(qpos, qval, 0, n - 1, 0);
  }
  
  int make_query(int ll, int rr) {
    return query(0, n - 1, 0, ll, rr);
  }
};

void solve(int vol, segtree &xt) {
  int lo = 0, hi = n - 1, ans = 0;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (xt.make_query(lo, mid) >= vol) {
      ans = mid;
      hi = mid - 1;
    }
    else lo = mid + 1;
  }
  xt.make_update(ans, vol);
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1;
  cin >> tt;
  while (tt--) {
    cin >> k >> n;

    segtree xt(100000);

    int j = 0;
    while (j < n) {
      int r, vol;
      string s;
      cin >> s;
      if (s == "b") {
        cin >> r >> vol;
        j += r;
        while (r--) solve(vol, xt);
      }
      else {
        j++;
        vol = stoi(s);
        solve(vol, xt);
      }
    }

    int cnt = 0, waste = 0;
    for (int i = 0; i < 100000; i++) {
      if (xt.a[i] == k) {
        break;
      }
      else {
        cnt++;
        waste += xt.a[i];
      }
    }

    cout << cnt << " " << waste << "\n";
  }

  return 0;
}
