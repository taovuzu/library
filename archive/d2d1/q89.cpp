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

int n, m;
char a[505][505];
vector<array<int, 3>> ans;

bool isValid(int i , int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int i, int j) {
  if (a[i][j] != '.') return;
  ans.push_back({1, i, j});
  a[i][j] = 'B';
  for (auto p : {make_pair(-1, 0), {0, -1}, {0, 1}, {1, 0}}) {
    if (isValid(i + p.first, j + p.second)) dfs(i + p.first, j + p.second);
  }
  bool flag = false;
  for (auto p : {make_pair(-1, 0), {0, -1}, {0, 1}, {1, 0}}) {
    if (isValid(i + p.first, j + p.second) && a[i + p.first][j + p.second] == 'B') flag = true;
  }
  if (flag) {
    a[i][j] = 'R';
    ans.push_back({2, i, j});
    ans.push_back({3, i, j});
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        dfs(i, j);
      }
    }
  }

  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << (ans[i][0] == 1 ? 'B' : (ans[i][0] == 2) ? 'D' : 'R') << " " << ans[i][1] + 1 << " " << ans[i][2] + 1 << "\n";
  }

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
