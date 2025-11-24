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

bool isValid(int x, int b) {
  string s = to_string(x);
  string s1 = to_string(b);
  string s2;
  for (int i = 0; i < s.size(); i++) {
    if(s[i] == '7' || s[i] == '4') s2 += s[i];
  }

  return s2 == s1;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int a, b;
  cin >> a >> b;

  int ans = 0;
  for(int i = max(b, a + 1); i <= 999999; i++) {
    if (isValid(i, b)) {
      ans = i;
      break;
    }
  }

  cout << ans << "\n";

  return 0;
}
