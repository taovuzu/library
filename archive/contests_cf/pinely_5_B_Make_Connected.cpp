// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv)
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifdef LOCAL
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

class dsu {
 public:
  vector<int> p;
  int n;
  int comp;

  dsu(int _n) : n(_n) {
    comp = n;
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
      comp--;
      return true;
    }
    return false;
  }

  bool isConnected() {
    return comp <= 2;
  }
};

int n;

bool allCov(vector<vector<char>> &a) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 2; j++) {
      if (a[i][j] == '#' && a[i][j + 1] == '#' && a[i][j + 2] == '#') return false;
    }
  }

  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '#' && a[i + 1][j] == '#' && a[i + 2][j] == '#') return false;
    }
  }

  dsu d(n * n + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int pos = i * n + j;
      if (a[i][j] == '#') {
        if (i && a[i - 1][j] == '#') d.unite(pos, (i - 1) * n + j);
        if (j && a[i][j - 1] == '#') d.unite(pos, i * n + (j - 1));
      }
      else {
        d.unite(pos, n * n);
      }
    }
  }

  return d.isConnected();
}

bool dfs(int i, int j, int x, int y, int curr, vector<vector<char>> &a) {
  if (i < 0 || i >= n || j < 0 || j >= n) {
    debmat(a, n, n);
    return allCov(a);
  }

  a[i][j] = '#';
  return dfs(i + (curr ? 0 : x), j + (curr ? y : 0), x, y, !curr, a);
}

void solve() {
  cin >> n;

  int x = 0, y = 0;
  vector a(n, vector<char> (n));
  vector<int> row(n), col(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == '#') {
        row[i]++, col[j]++;
        x = i, y = j;
      }
    }
  }

  bool flag = false;
  vector<vector<char>> b = a;

  flag |= allCov(b);

  b = a;
  flag |= dfs(x, y, -1, -1, 0, b);
  flag |= dfs(x, y, 1, 1, 1, b);

  b = a;
  flag |= dfs(x, y, -1, -1, 1, b);
  flag |= dfs(x, y, 1, 1, 0, b);

  b = a;
  flag |= dfs(x, y, -1, 1, 1, b);
  flag |= dfs(x, y, 1, -1, 0, b);

  b = a;
  flag |= dfs(x, y, -1, 1, 0, b);
  flag |= dfs(x, y, 1, -1, 1, b);


  cout << (flag ? "YES" : "NO") << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    pr(t_);
    solve();
  }

  return 0;
}
