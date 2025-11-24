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

  vector<int> b;
  int pow = k;
  b.push_back(1);
  if(abs(k) <= 1) {
    if(k == -1 || k == 0) b.push_back(k);
  }
  else {
    while(pow <= (1e18)) {
      b.push_back(pow);
      pow *= k;
    }
  }

  int ans = 0, sum = 0;;
  map<int, int> mp;
  mp[0] = 1;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    for (int j = 0; j < b.size(); j++) {
      if(mp.find(sum - b[j]) != mp.end()) ans += mp[sum - b[j]];
    }
    mp[sum]++;
  }

  cout << ans << "\n";

  return 0;
}
