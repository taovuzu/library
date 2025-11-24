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

const int mod = 1e9 + 7;
int n;

int solve(int row, int col, int flow, vector<string> &a, vector<vector<vector<int>>> &dp) {
  if (col >= n) return 0;
  if (row < 0 || row >= 3) return 0;
  if (a[row][col] == '#') return 0;
  if (col == n - 1 && row == 2) return flow == 0;

  if (dp[row][col][flow] != -1) return dp[row][col][flow];

  int ans = 0;
  if (flow == 0) {
    ans = (ans + solve(row, col + 1, 2, a, dp)) % mod;
  }
  else if (flow == 1) {
    ans = (ans + solve(row, col + 1, 2, a, dp)) % mod;
  }
  else {
    ans = (ans + solve(row + 1, col, 0, a, dp)) % mod;
    ans = (ans + solve(row - 1, col, 1, a, dp)) % mod;
  }

  return dp[row][col][flow] = ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1, cc = 0;
  cin >> tt;
  while (tt--) {
    cin >> n;

    vector<string> a(3);
    for (int i = 0; i < 3; i++) {
      cin >> a[i];
    }

    vector<vector<vector<int>>> dp(3, vector<vector<int>> (n, vector<int> (3, -1)));
    int ans = solve(0, 0, 2, a, dp);
    cout << "Case #" << ++cc << ": " << ans << "\n";
  }

  return 0;
}
