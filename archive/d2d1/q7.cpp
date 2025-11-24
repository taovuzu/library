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

int n, x, y, k, c;
string s;
int ll[200100], rr[200100];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> x >> y >> k >> s;

  k = 0;
  for (int i = 0, p = -1; i <= n; i++) {
    if (i == n || s[i] == '1') {
      ll[k] = p + 1;
      rr[k] = i - 1;
      c += (rr[k] - ll[k] + 1) / y;
      k++;
      p = i;
    }
  }

  cout << (c - x + 1) << "\n";
  k = 0;
  while(c >= x) {
    while(rr[k] - ll[k] + 1 < y) k++;
    ll[k] += y;
    cout << ll[k] << " ";
    c--;
  }

  return 0;
}