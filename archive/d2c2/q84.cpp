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

const int mod = 1e9 + 9;

template <typename T>
T binpow(T a, T b, T m = 0) {
    T res = 1;
    if (m != 0)
        a %= m;
    while (b > 0) {
        if (b & 1) {
            res = m ? (res * a % m) : (res * a);
        }
        a = m ? (a * a % m) : (a * a);
        b >>= 1;
    }
    return res;
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  int used = (n / k) * (k - 1) + (n % k);
  pr(used);
  if (used >= m) {
    cout << m << "\n";
  }
  else {
    int x = m - used;
    int ans = (((binpow(2LL, x + 1, mod) - 2 + mod) * k) % mod) + ((m - x * k) % mod);
    ans %= mod;
    cout << ans << "\n";
    pr(x);
  }

  return 0;
}