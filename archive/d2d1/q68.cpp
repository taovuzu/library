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

vector<string> a(20);
vector<vector<double>> mat(20, vector<double> (20)), dp(100, vector<double> (20));

void solve(int idx, int l, int r) {
  if (l == r) {
    dp[idx][l] = 1;
    return ;
  }
  int mid = (l + r) >> 1;
  int nIdx = idx << 1;
  solve(nIdx, l, mid);
  solve(nIdx + 1, mid + 1, r);
  for (int i = 1; i <= mid; i++) {
    for (int j = mid + 1; j <= r; j++) {
      dp[idx][i] += (dp[nIdx][i] * dp[nIdx + 1][j] * mat[i][j]);
      dp[idx][j] += (dp[nIdx][i] * dp[nIdx + 1][j] * mat[j][i]);
    }
  }
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int i = 1; i <= 16; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= 16; i++) {
    for (int j = 1; j <= 16; j++) {
      cin >> mat[i][j];
      mat[i][j] /= 100;
    }
  }

  solve(1, 1, 16);
  for (int i = 1; i <= 16; i++) {
    cout << setprecision(2) << fixed << left << setw(10) << a[i] << " p=" << dp[1][i] * 100 << "%\n";
  }

  return 0;
}
