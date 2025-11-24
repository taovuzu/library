// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
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

class dsu{
  public:
  int n;
  vector<int> a;

  dsu (int n_) : n(n_) {
    a.resize(n);
    iota(a.begin(), a.end(), 0);
  }

  inline int get(int x) {
    return x == a[x] ? x : (a[x] = get(a[x]));
  }

  inline bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return false;
    a[x] = y;
    return true;
  }

  int comp(){
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == i) cnt++;
    }
    return cnt;
  }
};

void solve() {
  int n, e;
  while (cin >> n >> e) {   
    int j = 0;
    char u, v;
    dsu d(n);
    map<char, int> mp;
    for (int i = 0; i < e; i++) {
      cin >> u >> v;
      if (mp.find(u) == mp.end()) mp[u] = j++;
      if (mp.find(v) == mp.end()) mp[v] = j++;
      d.unite(mp[u], mp[v]);
    }
    e += (d.comp() - 1);
    cout << (e - n + 2) << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
