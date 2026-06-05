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

map<char, vector<char>> g;
map<char, int> disc, low, inStack;
vector<char> stk;
vector<vector<char>>  ans;
int n, timer;

void tarjan(char u) {
  disc[u] = low[u] = timer;
  inStack[u] = 1;
  stk.push_back(u);

  for (auto v : g[u]) {
    if (disc.find(v) == disc.end()) {
      timer++;
      tarjan(v);
      low[u] = min(low[u], low[v]);
    }
    else if (inStack.find(v) != inStack.end()) {
      low[u] = min(low[u], disc[v]);
    }
  }

  if (disc[u] == low[u]) {
    vector<char> tmp;
    while (!stk.empty() && stk.back() != u) {
      tmp.push_back(stk.back());
      inStack.erase(stk.back());
      stk.pop_back();
    }

    tmp.push_back(u);
    inStack.erase(u);
    stk.pop_back();
    sort(tmp.begin(), tmp.end());
    ans.push_back(tmp);
  }
}

void solve() {
  g.clear();
  disc.clear();
  low.clear();
  inStack.clear();
  stk.clear();
  ans.clear();
  timer = 0;

  for (int i = 0; i < n; i++) {
    array<char, 6> a;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];

    for (int k = 0; k < 6; k++) g[a[k]];

    for (int j = 0; j < 5; j++) {
      if (a[j] != a[5]) {
        g[a[j]].push_back(a[5]);
      }
    }
  }


  for (auto &[u, _]: g) {
    if (disc.find(u) == disc.end()) {
      tarjan(u);
    }
  }

  sort(ans.begin(), ans.end());
  for (auto &tmp : ans) {
    for (int i = 0; i < tmp.size(); i++) {
      cout << tmp[i] << " \n"[i == tmp.size() - 1];
    }
  }

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 0;
  while (cin >> n && n) {
    if (tt++) cout << "\n";
    solve();
  }

  return 0;
}
