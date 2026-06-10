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

  int tt=1;  cin>>tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());
    int ans = n;
    int fo = n, fe = n, lo = -1, le = -1;
    for (int i = 0; i < n; i++) {
      if ((a[i] & 1) && (fo == n)) {
        fo = i;
      }
      if ((a[i] % 2 == 0) && (fe == n)) {
        fe = i;
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      if ((a[i] & 1) && (lo == -1)) {
        lo = i;
      }
      if ((a[i] % 2 == 0) && (le == -1)) {
        le = i;
      }
    }

    ans = min((fe + (n - 1 - le)), (fo + (n - 1 - lo)));
    cout << ans << "\n";
  }
  return 0;
}
