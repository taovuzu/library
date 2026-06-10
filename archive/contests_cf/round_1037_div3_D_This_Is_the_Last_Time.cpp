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

int n, k;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1;
  cin >> tt;
  while (tt--) {
    cin >> n >> k; 
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    sort(a.begin(), a.end());
    int ans = k;
    for (int i = 0; i < n; i++) {
      if (a[i][0] <= ans && ans <= a[i][1]) ans = max(ans, a[i][2]);
    }

    cout << ans << "\n";
  }

  return 0;
}

