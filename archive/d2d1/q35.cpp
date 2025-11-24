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

int n, m, k;
int c[205][205];

string solve() {
  c[0][0] = 1;
  for (int i = 0; i <= 200; i++) {
    c[i][0] = 1;
    c[i][i] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = min(c[i - 1][j] + c[i - 1][j -1], 1001001001LL);
    }
  }

  if (c[n + m][n] < k) return "";
  string s = "";
  int l = m + n;
  for (int i = 0; i < l; i++) {
    if (n > 0 && c[n + m - 1][m] >= k) {
      s += 'a';
      n--;
    }
    else {
      s += 'z';
      k -= c[n + m - 1][m];
      m--;
    }
  }

  return s;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> k;

  cout << solve();

  return 0;
}
