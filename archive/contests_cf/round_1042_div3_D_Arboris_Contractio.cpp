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

const int MAXN = 200200;
int n;
vector<int> adj[MAXN];

int cnt(int u) {
  int ans = 0;
  for (int v : adj[u]) {
   if (adj[v].size() == 1) ans++;
  }
  return ans;
}

void solve() {
  int u, v;
  cin >> n;
  for (int i = 0; i < n; i++) adj[i].clear();
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }
  int ans = 0, maxi = 1;
  for (int i = 0; i < n; i++) {
    if(adj[i].size() == 1) ans++;
    maxi = max(maxi, cnt(i));
  }
  if (n == 2) ans = 1;

  cout << ans - maxi << "\n";
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
