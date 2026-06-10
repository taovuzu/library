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
    string s;
    cin >> n >> s;

    reverse(s.begin(), s.end());
    vector<int> ans;
    int r = n, l = 1;
    for (int i = 0; i < n - 1; i++) {
      if(s[i] == '>'){
        ans.push_back(r);
        r--;
      }
      else {
        ans.push_back(l);
        l++;
      }
    }

    ans.push_back(l);
    for(int i = 0; i < n; i++) {
      cout << ans[n - i - 1] << " \n"[i == n - 1];
    }

  }

  return 0;
}
