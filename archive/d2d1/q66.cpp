// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
// उखँ थाशवफुलपवँ पप फवसजडिऊँ यि लेटीप्चँ यि प फुलेंवळेद्ल् 
// भाशवँ उखँ चतुर्थः प्रश्नः ईवफवुल हवराधपँ नत्वूँ पलफपवुलँ वठउव्षँ प यखयबोप 
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define u64 unsigned long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif


int n, x;
const u64 MAX = 18446744073709551615ULL;
u64 p[25];

u64 solve(int idx, int sum, vector<vector<u64>> &dp) {
  pr(idx, sum);
  if (idx > n) return sum >= x;
  if (sum >= x) {
    return p[n - idx + 1];
  }
  if(dp[idx][sum] != MAX) return dp[idx][sum];

  u64 ans = 0ULL;
  for (int i = 1; i <= 6; i++) {
    ans += solve(idx + 1, sum + i, dp);
  }
  pr(ans);

  return dp[idx][sum] = ans;
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  p[0] = 1;
  for (int i = 1; i <= 24; i++) {
    p[i] = 6 * p[i - 1];
  }

  while (cin >> n >> x && n) {
    pr(n, x);
    vector<vector<u64>> dp(n + 1, vector<u64> (x + 1, MAX));
    u64 ans = solve(1, 0, dp);
    if (ans == 0ULL || ans == p[n]) {
      cout << (ans ? 1 : 0) << "\n";
    }
    else {
      u64 g = __gcd(ans, p[n]);
      cout << (ans / g) << "/" << (p[n] / g) << "\n";
    }
  }

  return 0;
}
