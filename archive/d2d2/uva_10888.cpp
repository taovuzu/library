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

const int inf = 1e9;
int dirx[] = {-1, 0, 0, 1}, diry[] = {0, -1, 1, 0};

int n, m, k;
vector<vector<int>> dist(25, vector<int> (25, inf));
vector<string> grid(50);
vector<int> dp(1LL << 20);

vector<pair<int, int>> findPos(char ch) {
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == ch) {
        ans.push_back({i, j});
      }
    }
  }
  return ans;
}

bool isValid(int u, int v) {
  return u >= 0 && v >= 0 && u < n && v < m && grid[u][v] != '#';
}

int bfs(int u, int v, int w, int z) {
  queue<pair<int, int>> qu;
  vector<vector<bool>> vis(50, vector<bool> (50));
  qu.push({u, v});
  int dis = 0;
  while (!qu.empty()) {
    int level = qu.size();
    while (level--) {
      int i = qu.front().first, j = qu.front().second;
      qu.pop();
      if (i == w && j == z) return dis;
      for (int _i = 0; _i < 4; _i++) {
        if (isValid(i + dirx[_i], j + diry[_i]) && !vis[i + dirx[_i]][j + diry[_i]]) {
          vis[i + dirx[_i]][j + diry[_i]] = true;
          qu.push({i + dirx[_i], j + diry[_i]});
        }
      }
    }
    dis++;
  }
  return inf;
}

int rec(int mask) {
  int idx = __builtin_popcountll(mask), ans = inf;
  if (idx == k) return 0;
  if (dp[mask] != -1) return dp[mask];
  for (int i = 0; i < k; i++) {
    if (mask & (1LL << i)) continue;
    ans = min(ans, dist[idx][i] + rec(mask | (1LL << i)));
  }
  return dp[mask] = ans;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
  vector<pair<int, int>> boxes = findPos('B'), pos = findPos('X');
  k = boxes.size();
  pr(k);
  pr(boxes);
  pr(pos);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      dist[i][j] = bfs(boxes[i].first, boxes[i].second, pos[j].first, pos[j].second);
    }
  }
  debmat(dist, k, k);
  for (int i = 0; i < (1LL << k); i++) {
    dp[i] = -1;
  }
  cout << rec(0) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
