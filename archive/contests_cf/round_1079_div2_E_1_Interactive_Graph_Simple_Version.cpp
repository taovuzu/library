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

int n, m, q, kCurr;
vector<int> pCurr;
int g[40][40];
int dp[40];
bool vis[40];

vector<int> ask(int k) {
  q++;
  cout << "? " << k << endl;
  cout.flush();

  int q;
  if (!(cin >> q) || q == -1) exit(0);
  if (q == 0) return {};

  vector<int> c(q);
  for (int i = 0; i < q; i++) {
    cin >> c[i];
  }
  return c;
}

void fetch() {
  if (q >= n + m) {
    pCurr.clear();
    return;
  }
  pCurr = ask(kCurr);
}

int rec(vector<int> pre) {
  int u = pre.back(), sz = 1;

  if (vis[u]) {
    int skip = dp[u];
    kCurr += skip;
    fetch();
    return skip;
  }

  vis[u] = true;
  kCurr++;
  fetch();

  while (!pCurr.empty()) {
    bool ext = (pCurr.size() > pre.size());
    if (ext) {
      for (int i = 0; i < pre.size(); i++) {
        if (pCurr[i] != pre[i]) {
          ext = false;
          break;
        }
      }
    }

    if (!ext) break;

    int v = pCurr[pre.size()];
    if (!g[u][v]) {
      g[u][v] = 1;
      m++;
    }

    sz += rec(pCurr);
  }

  return dp[u] = sz;
}

void solve() {
  cin >> n;

  m = 0, q = 0, kCurr = 1;
  for (int i = 0; i < 40; i++) {
    dp[i] = vis[i] = 0;
    for (int j = 0; j < 40; j++) g[i][j] = 0;
  }

  fetch();
  while (!pCurr.empty()) {
    rec(pCurr);
  }

  cout << "! " << m << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (g[i][j]) cout << i << " " << j << endl;
    }
  }
  cout.flush();
}

int32_t main() {
  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
