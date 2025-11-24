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

int initSum, goal, n;
double prob;
vector<vector<vector<double>>> dp(55, vector<vector<double>> (1005, vector<double> (1005, -1.0)));

double solve(int idx, int sum, int last) {
  if (idx > n) return sum >= goal;
  if (sum >= goal) return 1.0;
  if (last > sum) return 0.0;

  if(dp[idx][sum][last] != -1.0) return dp[idx][sum][last];

  double ans = 0;
  ans += prob * solve(idx + 1, sum + last, 1);
  ans += (1 - prob) * solve(idx + 1, sum - last, 2 * last);

  return dp[idx][sum][last] = ans;

}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> initSum >> goal >> n >> prob;
  prob /= 100;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= goal; j++) {
      for (int k = 0; k <= 1004; k++) {
        dp[i][j][k] = -1.0;
      }
    }
  }

  cout << solve(1, initSum, 1) << "\n";

  return 0;
}
