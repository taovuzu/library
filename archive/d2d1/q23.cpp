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

  int n, tt = 1;
  while (cin >> n) {
    cout << "Case " << tt++ << ":" << " ";
    int ans = 0, x;
    stack <int> sk;

    for (int i = 0; i < n; i++) {
      cin >> x;
      while (!sk.empty() && sk.top() > x) sk.pop();
      if ((!sk.empty() && sk.top() == x) || (x == 0)) continue;
      else {
        ans++;
        sk.push(x);
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
