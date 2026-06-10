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

    vector<int> a(n + 1), b(n + 1, 0);
    vector<vector<int>> c(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      c[a[i]].push_back(i);
    }

    int ans = 1, i = 1, j = c[a[0]].size() >= 2 ? c[a[0]][1] : -1;
    b[a[0]] = 1;
    while ((i < n) && (j != -1)) {
      int k = j + 1;
      for (; i <= j; i++) {
        while (c[a[i]].size() > b[a[i]] && c[a[i]][b[a[i]]] <= j) b[a[i]]++;
        if(c[a[i]].size() <= b[a[i]]) {
          k = -1;
          break;
        }
        else {
          k = max(c[a[i]][b[a[i]]], k);
        }
      }
      j = k;
      ans++;
    }

    cout << ans << "\n";

  }

  return 0;
}
