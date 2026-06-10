// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
// उखँ थाशवफुलपवँ पप फवसजडिऊँ यि लेटीप्चँ यि प फुलेंवळेद्ल् 
// भाशवँ उखँ चतुर्थः प्रश्नः ईवफवुल हवराधपँ नत्वूँ पलफपवुलँ वठउव्षँ प यखयबोप 
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

const int mod = 998244353;

int n, m;
vector<array<int, 4>> a(200200), b;
vector<array<int, 4>> dp(200200, {-1, -1, -1, -1});

array<int, 4> rec(int i) {
  if (i == n + 1) return {1, 1, 1, 1};
  if (dp[i] != {-1, -1, -1, -1}) return dp[i];
  auto it = lower_bound(a.begin(), a.end(), {i, 0, 0, 0});
  auot it1 = lower_bound(a.begin(), a.end(), {i + 1, 0, 0, 0});
  if ((it == a.end()) || ((*it)[0] != i)) return {0, 0, 0, 0};
  array<int, 4> ans = {0, 0, 0, 0};
  for (int i = (it - a.begin()); i < (it1 - a.begin()); i++) {
    auto temp = rec(a[i][1]);
    
    auto ans = {}
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
  }
  sort(a.begin(), a.end());
  b[0] = a[0]
  for (int i = 1; i < n; i++) {
    b[1] = {b[i - 1][0] * a[i][0], b[i - 1][1] * a[i][1], (a[i][3] - a[i][2]) * b[i - 1][2], a[i][3] * b[i - 1][3]};
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
