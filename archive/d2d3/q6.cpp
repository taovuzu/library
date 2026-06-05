// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv hr)
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

int maxn = 300300;

vector<int> dp(maxn, -1), a(maxn), b(maxn, -1);
vector g(maxn, vector<int>());
map<string, int> mp;
map<int, string> mp1;

int counter(int u) {
  int tmp = 0;
  for (auto ch : mp1[u]) {
    if (ch == 'r') tmp++;
  }
  return tmp;
}

int dfs(int u) {
  if (dp[u] != -1 && b[u]) return dp[u];

  dp[u] = u;
  b[u]++;
  for (auto v : g[u]) {
    int x = dfs(v), y = counter(x), z = counter(dp[u]);
    if (y < z) {
      dp[u] = x;
    }
    else if (y == z && mp1[x].size() <= mp1[dp[u]].size()) {
      dp[u] = x;
    }
  }

  return dp[u];
}

void solve() {
  int m, n, cnt = 0;
  cin >> m;

  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    for (auto &ch : s) {
      if ('A' <= ch && ch <= 'Z') {
        ch = (ch - 'A') + 'a';
      }
    }
    if (mp.find(s) == mp.end()) {
      mp1[cnt] = s;
      mp[s] = cnt++;
    }
    a[i] = mp[s];
  }

  cin >> n;
  for (int i = 0; i < n; i++) {
    string s, s1;
    cin >> s >> s1;
    for (auto &ch : s) {
      if ('A' <= ch && ch <= 'Z') {
        ch = (ch - 'A') + 'a';
      }
    }
    for (auto &ch : s1) {
      if ('A' <= ch && ch <= 'Z') {
        ch = (ch - 'A') + 'a';
      }
    }
    if (mp.find(s) == mp.end()) {
      mp1[cnt] = s;
      mp[s] = cnt++;
    }
    if (mp.find(s1) == mp.end()) {
      mp1[cnt] = s1;
      mp[s1] = cnt++;
    }
    g[mp[s]].push_back(mp[s1]);
  }

  int x = 0, y = 0;
  for (int i = 0; i < m; i++) {
    dfs(a[i]);
  }

  for (int i = 0; i < m; i++) {
    dfs(a[i]);
    x += counter(dfs(a[i]));
    y += mp1[dfs(a[i])].size();
  }

  cout << x << " " << y << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
