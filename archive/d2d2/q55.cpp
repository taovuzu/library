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

int n, m;
vector<int> dirx{0, -1, 1, 0}, diry{-1, 0, 0, 1};

bool isValid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void solve() {
  cin >> n >> m;

  int cnt = 0;
  vector mat(n, vector<char> (m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      if (mat[i][j] == '#') cnt++;
    }
  }

  if (cnt <= 2) {
    cout << -1 << "\n";
    return;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] != '#') continue;
      int x, y;
      for (int h = 0; h < 4; h++) {
        if (isValid(i + dirx[h], j + diry[h]) && mat[i + dirx[h]][j + diry[h]] == '#') x = i + dirx[h], y = j + diry[h];
      }
      mat[i][j] = '.';
      vector vis(n, vector<bool> (m));
      queue<array<int, 2>> qu;
      qu.push({x, y});
      vis[x][y] = true;
      int tmp = cnt - 1;
      while (!qu.empty()) {
        x = qu.front()[0], y = qu.front()[1];
        qu.pop();
        tmp--;
        for (int h = 0; h < 4; h++) {
          if (isValid(x + dirx[h], y + diry[h]) && mat[x + dirx[h]][y + diry[h]] == '#' && !vis[x + dirx[h]][y + diry[h]]) {
            vis[x + dirx[h]][y + diry[h]] = true;
            qu.push({x + dirx[h], y + diry[h]});
          }
        }
      }
      if (tmp != 0) {
        cout << 1 << "\n";
        return;
      }
      mat[i][j] = '#';
    }
  }

  cout << 2 << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
