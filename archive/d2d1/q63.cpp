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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector<int> a(n), b, d;
  for (int i = 0; i < n; i++) cin >> a[i];

  int ans = 0;
  if (n == 1) ans = a[0];
  else {
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (a[i] < 0) b.push_back(a[i]);
      else if (a[i] == 0) flag = true;
      else d.push_back(a[i]);
    }
    if (flag || (b.size() && d.size())) {
      ans = accumulate(d.begin(), d.end(), 0LL) - accumulate(b.begin(), b.end(), 0LL);
    }
    else {
      if (d.size()) {
        ans = accumulate(d.begin(), d.end(), 0LL);
        ans -= 2 * (*min_element(d.begin(), d.end()));
      }
      else {
        ans -= accumulate(b.begin(), b.end(), 0LL);
        ans += 2 * (*max_element(b.begin(), b.end()));
      }
    }
  }

  cout << ans << "\n";

  return 0;
}