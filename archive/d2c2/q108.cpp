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

    vector<array<int, 3>> a(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; i++) {
      cin >> a[i][0] >> a[i][1];
      a[i][2] = i + 1;
    }

    sort(a.begin(), a.end());

    int even = 0, odd = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
      if(i & 1) odd += a[i][1];
      else even += a[i][1];
    }

    cout << "YES" << "\n";

    if (even >= odd) {
      for (int i = 0; i < 2 * n - 1; i += 2) {
        cout << a[i][2] << " ";
      }
    }
    else {
      for (int i = 1; i < 2 * n - 1; i += 2) {
        cout << a[i][2] << " ";
      }
      cout << a[2 * n - 2][2];
    }

    cout << "\n";
  }

  return 0;
}
