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

void solve() {
  int l, r;
  cin >> l >> r;
  
  int ans = r - l + 1;
  ans -= (r / 2 - (l - 1) / 2);
  ans -= (r / 3 - (l - 1) / 3);
  ans -= (r / 5 - (l - 1) / 5);
  ans -= (r / 7 - (l - 1) / 7);
  ans += (r / 6 - (l - 1) / 6);
  ans += (r / 10 - (l - 1) / 10);
  ans += (r / 14 - (l - 1) / 14);
  ans += (r / 15 - (l - 1) / 15);
  ans += (r / 21 - (l - 1) / 21);
  ans += (r / 35 - (l - 1) / 35);
  ans -= (r / 105 - (l - 1) / 105);
  ans -= (r / 70 - (l - 1) / 70);
  ans -= (r / 42 - (l - 1) / 42);
  ans -= (r / 30 - (l - 1) / 30);
  ans += (r / 210 - (l - 1) / 210);
  
  cout << ans << "\n";
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
