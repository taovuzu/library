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

int n, m, k;
vector<int> a(505);
vector<int> b(100100);

class dsu{
  public:
  int n;
  vector<int> a;

  dsu(int n_) : n(n_) {
    a.resize(n);
    iota(a.begin(), a.end(), 0);
  }

  inline int get(int x) {
    return x == a[x] ? x : a[x] = get(a[x]);
  }

  inline bool unite(int x, int y) {
    x = get(x), y = get(y);
    if(x == y) return false;
    a[x] = y;
    return true;
  }
};


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> k;
  vector<vector<int>> mat(k, vector<int> (k, LLONG_MAX));
  dsu d(n);

  int l = 0;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    int x = a[i];
    while(x--) {
      b[l++] = i;
    }
    mat[i][i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;

    int x = b[u - 1], y = b[v - 1];
    if(mat[x][y] > c ) {
      mat[x][y] = c;
      mat[y][x] = c;
    }

    if(c == 0) d.unite(u - 1, v - 1);
  }

  for (int i = 1; i < n; i++) {
    if(b[i] == b[i - 1] && d.get(i) != d.get(i - 1)) {
      cout << "No" << "\n";
      return 0;
    }
  }


  cout << "Yes" << "\n";
  for (int k_ = 0; k_ < k; k_++) {
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        if (mat[i][k_] == LLONG_MAX || mat[k_][j] == LLONG_MAX) continue;
        mat[i][j] = min(mat[i][j] , mat[i][k_] + mat[k_][j]);
      }
    }
  }

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      if(mat[i][j] == LLONG_MAX) mat[i][j] = -1;
      cout << mat[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}