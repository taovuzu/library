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

const int MOD = 1e9 + 7;

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

class dsu{
  public:
  vector<int> a;
  int n;
  
  dsu(int n_) : n(n_){
    a.resize(n);
    iota(a.begin(), a.end(), 0);
  }

  inline int find(int x){
    while (x != a[x]) {
      x = a[x] = a[a[x]];
    }
    return x;
  }

  inline int unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    a[x] = y;
    return true;
  }

  int count() {
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) {
      b[find(i)] = 1;
    }
    return accumulate(b.begin(), b.end(), 0LL);
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  dsu d(n);
  for (int i = 0; i + k - 1 < n; i++) {
    int j = i, l = i + k - 1;
    while (j <= l) {
      d.unite(j, l);
      j++, l--;
    }
  }

  int ans = d.count();
  ans = binpow(m, ans, MOD);

  cout << ans << "\n";

  return 0;
}
