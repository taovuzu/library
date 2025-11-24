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

const int maxn = 66; // max range is 66 for int64_t
int C_pascal[maxn + 1][maxn + 1];

void build_pascal() {
    C_pascal[0][0] = 1;
    for (int n = 1; n <= maxn; ++n) {
        C_pascal[n][0] = C_pascal[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C_pascal[n][k] = C_pascal[n - 1][k - 1] + C_pascal[n - 1][k];
    }
}

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

int n;
double p;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  build_pascal();

  int tt = 1;
  cin >> tt;
  while (tt--) {
    cin >> n >> p;
    double ans = 0;
    for (int i = n; i <= 2 * n - 1; i++) {
      ans += ((C_pascal[2 * n - 1][i] * 1.0) * (binpow(p, i)) * binpow(1 - p, 2 * n - 1 - i));
    }
    cout << setprecision(2) << fixed << ans << "\n";
  }

  return 0;
}
