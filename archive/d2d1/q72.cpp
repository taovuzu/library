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
#define pr(...) \
  {             \
  }
#define debarr(a, n) \
  {                  \
  }
#define debmat(mat, row, col) \
  {                           \
  }
#endif

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }

  int comp() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (p[i] == i) cnt++;
    }
    return cnt;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int x, y, tt = 0;
  while (cin >> x >> y && (x > -1 && y > -1)) {
    tt++;
    map<int, int> mp;
    int k = 0;
    bool flag = true;
    if (x && y) {
      vector<array<int, 2>> a;
      if (mp.find(x) == mp.end()) mp[x] = k++;
      if (mp.find(y) == mp.end()) mp[y] = k++;
      a.push_back({mp[x], mp[y]});
      while (cin >> x >> y && (x && y)) {
        if (mp.find(x) == mp.end()) mp[x] = k++;
        if (mp.find(y) == mp.end()) mp[y] = k++;
        a.push_back({mp[x], mp[y]});
      }
      dsu d(k);
      for (int j = 0; j < a.size(); j++) {
        if(!d.unite(a[j][0], a[j][1])) {
          flag = false;
          break;
        }
      }
      if (flag)  flag = (d.comp() == 1);
    }
    
    cout << "Case " << tt << (flag ? " is a tree." : " is not a tree.") << "\n";
  }

  return 0;
}
