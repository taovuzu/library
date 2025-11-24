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

  int n;
  cin >> n;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i].resize(x);
    for (int j = 0; j < x; j++) {
      cin >> a[i][j];
    }
    sort(a[i].begin(), a[i].end());
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int l = (i - 1 + n) % n, r = (i + 1) % n;
    int x = a[i].size(), y = a[l].size(), z = a[r].size();
    int l1 = 0, r1 = 0, l2 = 0, r2 = 0;
    pr(l, r, i, x, y, z);
    for (int j = 1; j < x; j++) {
      int l3 = a[i][j - 1], r3 = a[i][j];
      while (l1 < y && a[l][l1] < l3) l1++;
      while (r1 < y && a[l][r1] <= r3) r1++;
      while (l2 < z && a[r][l2] < l3) l2++;
      while (r2 < z && a[r][r2] <= r3) r2++;
      pr(l1, r1, l2, r2, l3, r3);
      if ((r2 - l2) != (r1 - l1)) ans++;
      pr(ans);
    }
  }

  cout << ans << "\n";

  return 0;
}
