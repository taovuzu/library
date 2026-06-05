// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv hr)
#include <bits/stdc++.h>

using namespace std;

// #define int long long

#ifdef LOCAL
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

const int MAXN = 1005;
int n, m;
int grid[MAXN][MAXN];
int dist[MAXN][MAXN][4];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int get_mask(char c) {
  if (c == '+') return 15;
  if (c == '-') return 10;
  if (c == '|') return 5;
  if (c == '^') return 1;
  if (c == '>') return 2;
  if (c == '<') return 8;
  if (c == 'v') return 4;
  if (c == 'L') return 7;
  if (c == 'R') return 13;
  if (c == 'U') return 14;
  if (c == 'D') return 11;
  return 0;
}

bool has_door(int r, int c, int rot, int dir) {
  int mask = grid[r][c];
  int original_dir = (dir - rot + 4) % 4;
  return (mask >> original_dir) & 1;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch;
      cin >> ch;
      grid[i][j] = get_mask(ch);
    }
  }

  int xt, yt, xm, ym;
  cin >> xt >> yt >> xm >> ym;
  xt--, yt--, xm--, ym--;

  memset(dist, -1, sizeof(dist));

  queue<array<int, 3>> q;
  q.push({xt, yt, 0});
  dist[xt][yt][0] = 0;

  while (!q.empty()) {
    auto [r, c, rot] = q.front();
    q.pop();

    if (r == xm && c == ym) {
      cout << dist[r][c][rot] << "\n";
      return;
    }

    int d = dist[r][c][rot];

    int n_rot = (rot + 1) % 4;
    if (dist[r][c][n_rot] == -1) {
      dist[r][c][n_rot] = d + 1;
      q.push({r, c, n_rot});
    }

    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m && has_door(r, c, rot, i) && has_door(nr, nc, rot, (i + 2) % 4) && dist[nr][nc][rot] == -1) {
        dist[nr][nc][rot] = d + 1;
        q.push({nr, nc, rot});
      }
    }
  }

  cout << -1 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}