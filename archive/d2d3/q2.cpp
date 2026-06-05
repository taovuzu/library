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

const int MAX = 5005;
int n, m, timer, cnt;
vector<vector<int>> ans, g(MAX);
vector<int> stk, disc(MAX), low(MAX), inStack(MAX), comp(MAX);

void tarjan(int u) {
  disc[u] = low[u] = timer;
  stk.push_back(u);
  inStack[u] = 1;

  for (auto v : g[u]) {
    if (disc[v] == -1) {
      timer++;
      tarjan(v);
      low[u] = min(low[u], low[v]);
    }
    else if (inStack[v]) {
      low[u] = min(low[u], disc[v]);
    }
  }

  if (disc[u] == low[u]) {
    vector<int> a;
    while (!stk.empty() && stk.back() != u) {
      a.push_back(stk.back());
      inStack[stk.back()] = 0;
      comp[stk.back()] = cnt;
      stk.pop_back();
    }
    a.push_back(u);
    inStack[u] = 0;
    comp[u] = cnt;
    stk.pop_back();
    cnt++;

    ans.push_back(a);
  }
}

void solve() {
  ans.clear();
  stk.clear();
  timer = cnt = 0;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    disc[i] = low[i] = comp[i] = -1;
    inStack[i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
  }

  for (int i = 0; i < n; i++) {
    if (disc[i] == -1) {
      tarjan(i);
    }
  }

  vector<int> bottom_nodes; 

  for (auto &a : ans) {
    bool flag = true;
    for (auto x : a) {
      for (auto v : g[x]) {
        if (comp[x] != comp[v]) {
          flag = false;
          break; 
        }
      }
      if (!flag) {
        break; 
      }
    }

    if (flag) {
      for (auto x : a) {
        bottom_nodes.push_back(x);
      }
    }
  }

  sort(bottom_nodes.begin(), bottom_nodes.end());

  for (auto x : bottom_nodes) {
    cout << x + 1 << " ";
  }

  cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while (cin >> n >> m) {
    solve();
  }

  return 0;
}
