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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
      c[i] = max(a[i], b[i]);
    }

    reverse(b.begin(), b.end());
    int g = a[0], g1 = b[0];
    bool flag = true;
    for (int i = 1; i < n; i++) {
      if (__gcd(c[i], g) < a[i])  {
        flag = false;
        break;
      }
      if (__gcd(c[n - i - 1], g1) < b[i]) {
        flag = false;
        break;
      }
      g = a[i], g1 = b[i];
    }

    cout << (flag ? "YES" : "NO") << "\n";
  }

  return 0;
}
