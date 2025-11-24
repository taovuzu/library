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

class dsu {
 public:
  vector<int> p, parity;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    parity.resize(n, 0);
    iota(p.begin(), p.end(), 0);
  }

  inline array<int, 2> get(int x) {
    if (x == p[x]) return {x, parity[x]};
    auto temp = get(p[x]);
    p[x] = temp[0];
    parity[x] ^= temp[1];
    return {p[x], parity[x]};
  }

  inline bool unite(int x, int y, int rel) {
    auto px = get(x);
    auto py = get(y);
    if (px[0] == py[0]) {
      return ((px[1] ^ py[1]) == rel);
    }
    p[px[0]] = py[0];
    parity[px[0]] = px[1] ^ py[1] ^ rel;
    return true;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, q;
  cin >> n >> m >> q;

  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mp[s] = i;
  }

  dsu d(n);
  for (int i = 0; i < m; i++) {
    int t;
    string s, s1;
    cin >> t >> s >> s1;

    int x = mp[s], y = mp[s1];
    bool ok;
    if (t == 1) {
      ok = d.unite(x, y, 0);
    } else {
      ok = d.unite(x, y, 1);
    }

    cout << (ok ? "YES" : "NO") << "\n";
  }

  while (q--) {
    string s, s1;
    cin >> s >> s1;
    int x = mp[s], y = mp[s1];
    auto pu = d.get(x);
    auto pv = d.get(y);
    if (pu[0] == pv[0]) {
      if ((pu[1] ^ pv[1]) == 0)
        cout << 1 << '\n';
      else
        cout << 2 << '\n';
    } else {
      cout << 3 << '\n';
    }
  }

  return 0;
}