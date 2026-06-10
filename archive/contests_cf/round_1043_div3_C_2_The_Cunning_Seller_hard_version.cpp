// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
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

int cnt(int n) {
  int tmp = 0; 
  while (n >= 3) tmp++, n /= 3;
  return tmp;
}

void solve() {
  int n, k, n1, ans = 0;
  cin >> n >> k;
  n1 = n;
  while (n) {
    int x = cnt(n), z = binpow(3, x), y = (n / z);
    ans += y * (z * 3 + x * z / 3);
    k -= y;
    n %= z;
  }
  if (k < 0) {
    cout << "-1" << "\n";
    return;
  }
  while (n) {
    if (k > 2) ans += 
    int x = cnt(n), z = binpow(3, x), y = (n / z), w = z / 3;
    ans += y * (z * 3 + x * z / 3);
    n %= z;
  }
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
