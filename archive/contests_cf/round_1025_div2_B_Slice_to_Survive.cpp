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

int solve(int x) {
  int ans = 0;
  while (x > 1) {
    ans++;
    x = (x + 1) / 2;
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    int ans = 0, ans1 = 0;
    ans = (n > 1) + (m > 1) + solve(min(x, n - x + 1)) + solve((m + 1) / 2);
    ans1 = (n > 1) + (m > 1) + solve(min(y, m - y + 1)) + solve((n + 1) / 2);

    cout << min(ans, ans1) << "\n";

  }

  return 0;
}
