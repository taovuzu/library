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

int n, m, r1, c1, r2, c2;
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
vector<string> a(505);

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> r1 >> c1 >> r2 >> c2;
  r1--, c1--, r2--, c2--;
  auto isValid = [&n, &m, &a](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.';
  };
  bool flag = a[r2][c2] == 'X', flag1 = false;
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    int x1 = r2 + dx[i], y1 = c2 + dy[i];
    if (isValid(x1, y1)) cnt++;
  }
  for (int i = 0; i < 4; i++) {
    int x1 = r1 + dx[i], y1 = c1 + dy[i];
    if (x1 == r2 && y1 == c2) flag1 = true;
  }
  flag |= cnt >= 2;
  flag |= cnt >= 1 && flag1;
  a[r2][c2] = '.';
  vector vis(n, vector<bool> (m));
  queue<array<int, 2>> qu;
  qu.push({r1, c1});
  while (!qu.empty()) {
    int x = qu.front()[0], y = qu.front()[1];
    qu.pop();
    for (int i = 0; i < 4; i++) {
      int x1 = x + dx[i], y1 = y + dy[i];
      if (isValid(x1, y1) && !vis[x1][y1]) {
        qu.push({x1, y1});
        vis[x1][y1] = true;
      }
    }
  }

  if (vis[r2][c2] && flag) {
    cout << "YES";
  }
  else {
    cout << "NO";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
