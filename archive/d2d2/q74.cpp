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

string topsort(vector<vector<int>> &g,map<char, int> &mp, map<int, char> &mp1) {
  priority_queue<char, vector<char>, greater<char>> pq;

  vector<int> inDeg(g.size());
  for (int i = 0; i < g.size(); i++) {
    for (int j = 0; j < g[i].size(); j++) {
      inDeg[g[i][j]]++;
    }
  }

  for (int i = 0; i < g.size(); i++) {
    if (!inDeg[i]) {
      pq.push(mp1[i]);
    }
  }

  string ans = "";
  while (!pq.empty()) {
    char ch = pq.top();
    ans += ch;
    pq.pop();
    int node = mp[ch];
    for (auto v : g[node]) {
      inDeg[v]--;
      if (!inDeg[v]) {
        pq.push(mp1[v]);
      }
    }
  }

  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;

  map<char, int> mpl, mpr, mpt, mpb, mp;
  map<int, char> mp1;
  int currNode = 0;
  vector mat(n, vector<char> (m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      if (mat[i][j] == '.') continue;
      if (!mp.count(mat[i][j])) {
        mp[mat[i][j]] = currNode;
        mp1[currNode] = mat[i][j];
        currNode++;
        mpl[mat[i][j]] = mpr[mat[i][j]] = j;
        mpt[mat[i][j]] = mpb[mat[i][j]] = i;
      }
      else {
        mpl[mat[i][j]] = min(mpl[mat[i][j]], j);
        mpr[mat[i][j]] = max(mpr[mat[i][j]], j);
        mpt[mat[i][j]] = min(mpt[mat[i][j]], i);
        mpb[mat[i][j]] = max(mpb[mat[i][j]], i);
      }
    }
  }

  vector g(mp.size(), vector<int>());
  for (auto [ch, node] : mp) {
    int l = mpl[ch], r = mpr[ch], t = mpt[ch], b = mpb[ch];
    set<char> xt;
    for (int i = t; i <= b; i++) {
      for (int j = l; j <= r; j++) {
        if (mat[i][j] != ch && xt.count(mat[i][j]) == 0) {
          g[node].push_back(mp[mat[i][j]]);
          xt.insert(mat[i][j]);
        }
      }
    }
  }

  string ans = topsort(g, mp, mp1);
  cout << ((ans.size() < g.size()) ? "ERROR!" : ans) << "\n";

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
