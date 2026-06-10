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

    if(s[0] == '1') {
      int i = 1;
      for(; i < n; i++) {
        if (s[i] == '0') break;
      }

      while(s[i] == '0' && i < n) i++;
      reverse(s.begin(), s.begin() + i);
    }
    else {
      int i = 1;
      for(; i < n; i++) {
        if (s[i] == '1') break;
      }
      int j = i + 1;
      for(; j < n; j++) {
        if(s[j] == '0') break;
      }
      while(s[j] == '0' && j < n) j++;
      reverse(s.begin() + i,  s.begin() + j);
    }


    int ans = n;
    char curr = '0';
    for (int i = 0; i < n; i++) {
      if(s[i] != curr) {
        ans++;
        curr = curr == '0' ? '1' : '0';
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
