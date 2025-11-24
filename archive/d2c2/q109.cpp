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

const int MOD = 998244353;
const int MAXN = 5005;

long long fac[MAXN + 1];
long long inv[MAXN + 1];

/** 
 * @return x^n modulo m in O(log n) time.
 * Note: Ensure m * m < 2^63 to avoid overflow.
 */
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

/** Precomputes factorials from 0 to MAXN modulo p. */
void factorial(long long p) {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) { 
        fac[i] = fac[i - 1] * i % p; 
    }
}

/**
 * Precomputes modular inverse factorials from 0 to MAXN modulo p in O(n + log p) time.
 */
void inverses(long long p) {
    inv[MAXN] = exp(fac[MAXN], p - 2, p);
    for (int i = MAXN; i >= 1; i--) { 
        inv[i - 1] = inv[i] * i % p; 
    }
}

/** 
 * @return nCr modulo p.
 */
long long choose(long long n, long long r, long long p) {
    return fac[n] * inv[r] % p * inv[n - r] % p;
}

void solve(int x, int y, int &ans) {
  int  cnt = 0;

  for (int i = 0; i <= min(x, y); i++) {
    int temp = ((choose(x, i, MOD) * choose(y, i, MOD)) % MOD * fac[i] ) % MOD;
    cnt = (cnt + temp) %  MOD;
  }
  ans = (ans * cnt) % MOD;   
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  factorial(MOD);
	inverses(MOD);

  int x, y, z;
  cin >> x >> y >> z;

  int ans = 1;
  solve(x, y, ans);
  solve(x, z, ans);
  solve(y, z, ans);

  cout << ans << "\n";

  return 0;
}
