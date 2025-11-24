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

int n, c, k;
vector<double> a(55);

bool check(double mid) {
  int cnt = 0, tot = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= mid) {
      tot++;
      cnt += max(0LL, (int) floor(a[i] / mid) - 1);
    }
  }
  return (tot + min(c, cnt)) >= k;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cin >> c >> k;
  double lo = 0, hi = *max_element(a.begin(), a.begin() + n), ans = 0;
  for (int i = 0; i <= 90; i++) {
    double mid = (lo + hi) / 2;
    if (check(mid)) {
      ans = mid;
      lo = mid;
    }
    else hi = mid;
  }

  cout << setprecision(12) << fixed << ans << "\n";

  return 0;
}
