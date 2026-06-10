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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int x = a[k - 1];
    sort(a.begin(), a.end());
    int i = 0;
    while (a[i] != x) i++;
    int curr = 0;
    while (i < n - 1) {
      int time = a[i + 1] - a[i];
      if (a[i] >= time + curr) i++;
      else break;
      curr += time;
    }

    cout << (i == n - 1 ? "YES" : "NO") << "\n";
  }

  return 0;
}
