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

string ans;
int n;

void check(string s) {
  for (int i = 0; i <= 9; i++) {
    for(int j = 0; j < n; j++) {
      s[j] = (s[j] == '9' ? '0' :(char)((int) s[j] + 1));
    }
    if (lexicographical_compare(s.begin(), s.end(), ans.begin(), ans.end())) {
      ans = s;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> n >> s;

  ans = s;
  for (int i = 0; i < n; i++) {
    rotate(s.begin(), s.begin() + 1, s.end());
    check(s);
  }

  cout << ans << "\n";

  return 0;
}
