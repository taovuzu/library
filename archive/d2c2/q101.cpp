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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  string s;
  cin >> n >> s;

  int r = 0, b = 0;
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      if(s[i] == 'r') r++;
    }
    else {
      if(s[i] == 'b') b++;
    }
  }

  int ans = max(r, b);
  
  r = 0, b = 0;
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      if(s[i] == 'b') b++;
    }
    else {
      if(s[i] == 'r') r++;
    }
  }
  ans = min(max(r, b), ans);

  cout << ans << "\n";

  return 0;
}
