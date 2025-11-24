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

int n, x, ans;
string s;

void solve(char ch) {
  int cnt = 0, i = 0, j = 0;
  while (i < n) {
    while (j < n && (cnt + (s[j] == ch) <= x)) {
      if(s[j++] == ch)  cnt++;
    }
    ans = max(ans, j - i);
    if (s[i++] == ch) cnt--;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> x >> s;
  ans = x;

  solve('a');
  solve('b');

  cout << ans << "\n";

  return 0;
}
