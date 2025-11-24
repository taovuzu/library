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

  string s;
  cin >> s;

  cout << "0 ";
  // pr(0, s);
  for (int i = 1; i < s.size(); i++) {
    if (i == s.size() - 1) {
      if (s[i] == 'a') {
        cout << "1";
        // reverse(s.begin(), s.end());
      }
      else {
        cout << "0";
      }
      // pr(0, s);
    }
    else if(s[i] != s[i + 1]) {
      cout << "1 ";
      // reverse(s.begin(), s.begin() + i + 1);
      // pr(1, s);
    }
    else {
      cout << "0 ";
      // pr(0, s);
    }
  }

  return 0;
}
