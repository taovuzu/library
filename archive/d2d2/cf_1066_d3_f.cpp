// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। ॥ (iii-iv)
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

int n;
map<int, vector<array<int, 2>>> mp;
map<array<int, 2>, int> dp;

int dist(array<int, 2> &x, array<int, 2> &y) {
  return abs(x[0] - y[0]) + abs(x[1] - y[1]);
}

int rec(int level, int dir) {
  if (dp.find({level, dir}) != dp.end()) return dp[{level, dir}];
  int sum = dist(mp[level][0], mp[level][mp[level].size() - 1]);
  auto it1 = mp.upper_bound(level);
  if (it1 == mp.end()) return sum;
  auto it = (*it1).first;
  array<int, 2> curr = mp[level][dir ? 0 : mp[level].size() - 1];
  return dp[{level,dir}] = sum + min(dist(curr, mp[it][0]) + rec(it, 0), dist(curr, mp[it][mp[it].size() - 1]) + rec(it, 1));
}

void solve() {
  cin >> n;
  mp[0].push_back({0, 0});
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    mp[max(x, y)].push_back({x, y});
  }
  for (auto &[_, a] : mp) {
    sort(a.begin(), a.end(), [](auto &x, auto &y) {
      if (x[0] == y[0]) return x[1] > y[1];
      return x[0] < y[0];
    });
  }
  cout << rec(0, 0) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
