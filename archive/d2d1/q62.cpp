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
  
  vector<int> a(n), b, c;
  for (int i = n - 1; i >= 0; i--) {
    cin >> a[i];
  }

  c.push_back(-1);
  b.push_back(a[0]);
  for (int i = 1; i < n; i++) {
    int lo = 0, hi = b.size(), ans = b.size();
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (b[mid] < a[i]) {
        ans = mid;
        hi = mid - 1;
      }
      else lo = mid + 1;
    }
    b.push_back(min(b.back(), a[i]));
    c.push_back(i - ans - 1);
  }

  for (int i = n - 1; i >= 0; i--) {
    cout << c[i] << " ";
  }


  return 0;
}
