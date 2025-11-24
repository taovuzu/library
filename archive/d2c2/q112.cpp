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

template <typename T>
T binpow(T a, int b, T m = 0) {
  T res = 1;

  if constexpr (std::is_integral<T>::value) {
    if (m != 0) a %= m;
  }

  while (b > 0) {
    if (b & 1) {
      if constexpr (std::is_integral<T>::value) {
        res = m ? (res * a % m) : (res * a);
      } else {
        res *= a;
      }
    }
    if constexpr (std::is_integral<T>::value) {
      a = m ? (a * a % m) : (a * a);
    } else {
      a *= a;
    }
    b >>= 1;
  }

  return res;
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int m, n;
  cin >> m >> n;

  long double ans = m;
  for (int i = 1; i < m ; i++) {
    ans -= binpow((1.0) * i / m, n);
  }

  cout << fixed << setprecision(12) << ans << "\n";

  return 0;
}
