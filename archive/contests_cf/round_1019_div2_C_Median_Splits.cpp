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
    // pr(tt);
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1), pref(n + 1);
    pref[0] = 0;
    int last = -1, last2 = -1;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pref[i] = pref[i - 1];
      if (a[i] <= k) {
        pref[i]++;
      }

      if(i <= n - 1 && pref[i] >= (i + 1) / 2) {
        if(last != -1 && (pref[i] - pref[last]) >= (i - last + 1) / 2) {
          flag = true;
        }
        else last = i;
      }
    }
    
    reverse(a.begin() + 1, a.end());
    for (int i = 1; i < n; i++) {
      pref[i] = pref[i - 1];
      if (a[i] <= k) {
        pref[i]++;
      }
      if(i <= n - 1 && pref[i] >= (i + 1) / 2) {
        if(last2 != -1 && (pref[i] - pref[last2]) >= (i - last2 + 1) / 2) {
          flag = true;
          break;
        }
        else last2 = i;
      }
      if(last != -1 && i <= n - last ) {
        if(pref[i] >= (i + 1) / 2) {
          // pr("suf", i);
          flag = true;
          break;
        }
      }
    }

    cout << (flag ? "YES" : "NO") << "\n";

  }

  return 0;
}
