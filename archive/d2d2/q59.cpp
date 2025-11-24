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



vector<array<int, 2>> trans(int n, int maskA, int maskB, const vector<vector<int>>& g) {
  vector<int> choosers; 
  int baseNextA = maskA;
  int baseNextB = maskB;

  for (int i = 0; i < n; i++) {
    bool hasA = (maskA >> i) & 1;
    bool hasB = (maskB >> i) & 1;

    if (hasA && hasB) {
      choosers.push_back(i);
    } else if (hasA) { 
      for (int neighbor : g[i]) {
        baseNextA |= (1 << neighbor);
      }
    } else if (hasB) { 
      for (int neighbor : g[i]) {
        baseNextB |= (1 << neighbor);
      }
    }
  }

  vector<array<int, 2>> res;
  int k = choosers.size();
  
  for (int choiceMask = 0; choiceMask < (1 << k); choiceMask++) {
    int nextA = baseNextA;
    int nextB = baseNextB;

    for (int i = 0; i < k; i++) {
      int u = choosers[i];
      if ((choiceMask >> i) & 1) { 
        for (int neighbor : g[u]) {
          nextA |= (1 << neighbor);
        }
      } else { 
        for (int neighbor : g[u]) {
          nextB |= (1 << neighbor);
        }
      }
    }
    res.push_back({nextA, nextB});
  }

  return res;
}

void solve() {
  int n;
  string know;
  cin >> n >> know;
  
  vector<string> a(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 'Y') g[i].push_back(j);
    }
  }

  int maskA = 0, maskB = 0;
  for (int i = 0; i < n; i++) {
    if (know[i] == 'Y') {
      maskA |= (1 << i);
      maskB |= (1 << i);
    }
  }

  map<array<int, 2>, int> mp;
  mp[{maskA, maskB}] = 0;
  queue<array<int, 2>> qu;
  qu.push({maskA, maskB});
  int day = 0;
  while (!qu.empty()) {
    int sz = qu.size();
    while (sz--) {
      auto [curA, curB] = qu.front(); 
      qu.pop();
      vector<array<int, 2>> nxt = trans(n, curA, curB, g);
      for (auto x : nxt) {
        if (!mp.count(x)) {
          qu.push(x);
          mp[x] = day + 1;
        }
      }
    }
    day++;
  }

  if (!mp.count({(1LL << n) - 1, (1LL << n) - 1})) {
    cout << -1 << "\n";
  }
  else {
    cout << mp[{(1LL << n) - 1, (1LL << n) - 1}] << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
