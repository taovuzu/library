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

const int MAXN = 1005;
const int MOD = 1e9 + 7;

long long fac[MAXN + 1];

long long exp(long long x, long long n, long long m) {
    x %= m;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

void factorial(long long p) {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) { 
        fac[i] = fac[i - 1] * i % p; 
    }
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  factorial(MOD);

  int n, m;
  cin >> n >> m;

  vector<int> a(n, 0);
  vector<int> b;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    a[x - 1] = 1;
  }
  int res = 1;
  int temp = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      temp++;
    }
    else {
      b.push_back(temp);
      res = (res * fac[temp]) % MOD;
      temp = 0;
    }
  }

  b.push_back(temp);
  res = (res * fac[temp]) % MOD;

  int ans = fac[accumulate(b.begin(), b.end(), 0LL)];
  ans = (ans * exp(res, MOD - 2, MOD)) % MOD;

  for (int i = 1; i < b.size() - 1; i++) {
    ans = (ans * exp(2, b[i] - 1, MOD)) % MOD;
  }

  cout << ans << "\n";

  return 0;
}