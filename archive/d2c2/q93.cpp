// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
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

int dp[1010][1010];

void sum(int i, int k) {
  int carry = 0;
  for (int i_ = 0; i_ <= 1000; i_++) {
    int sum = (dp[i][i_] + dp[k][i_] + carry) % 10;
    carry = (dp[i][i_] + dp[k][i_] + carry) / 10;
    dp[k][i_] = sum;
  }
}

void print(int n) {
  bool flag = false;
  for (int i = 1000; i >= 0; i--) {
    if (dp[n][i] != 0) flag = true;
    if (flag) {
      cout << dp[n][i];
    }
  }
  cout << "\n";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  dp[0][0] = 1;
  dp[1][0] = 2;
  dp[2][0] = 5;
  for (int i = 3; i <= 1000; i++) {
    sum(i - 1, i);
    sum(i - 2, i);
    sum(i - 3, i);
    sum(i - 1, i);
  }

  int n;
  while (cin >> n) print(n);

  return 0;
}
