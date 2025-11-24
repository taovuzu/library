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

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  map<int, int> mp, mp1;
  vector<int> pref(n), suff(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    pref[i] = a[i] % k == 0 ? mp[a[i] / k] : 0;
    mp[a[i]]++;
  }
  for (int i = n - 1; i >= 0; i--) {
    suff[i] =  mp1[a[i] * k];
    mp1[a[i]]++;
  }
  for (int i = 1; i < n; i++) {
    ans += (pref[i] * suff[i]);
  }

  cout << ans << '\n';

  return 0;
}
