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

__int128 gcd(__int128 a, __int128 b) {
  return b ? gcd(b, a % b) : a;
}

__int128 lcm128(__int128 a, __int128 b) {
  return a / gcd(a, b) * b;
}

void print(__int128 num, __int128 den) {
  __int128 g = gcd(num, den);
  num /= g;
  den /= g;
  cout << (long long)num << "/" << (long long)den << "\n";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T, W, B;
  cin >> T >> W >> B ;

  __int128 t = T, w = W, b = B;
  __int128 lcm = lcm128(w, b);

  __int128 ans = t / lcm;
  ans += ans * (min(b, w) - 1);
  ans += min(t % lcm, min(b, w) - 1);

  print(ans, t);

  return 0;
}
