#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

const int mod = 1e9 + 7;

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

int convertBinaryString(const string &str) {
  int result = 0;
  for (char c : str) {
      result = result * 2 + (c - '0');
      result %= mod;
  }
  return result;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    int n;
    string s, s0;
    cin >> n >> s;

    int last = 0;
    for(int i = 0; i < n; i++){
      s0 += s[i];
      if(s[i] == '1') last = i;
    }
    for(int i = 0; i <= last; i++){
      s0[i] = s0[i] == '0' ? '1' : '0';
    }

    string s1 = s;
    s1.erase(s1.begin());
    s1 += '0';

    int numS0 = convertBinaryString(s0);
    int numS1 = convertBinaryString(s1);

    int x = binpow(2, n - 1, mod);
    int y = binpow(2, n , mod);

    int x_inv = binpow(x, mod - 2, mod);
    int y_inv = binpow(y, mod - 2, mod);

    pr(x_inv, y_inv);
    int ans = (1LL * numS0 * x_inv % mod + 1LL * numS1 * y_inv % mod) % mod;

    cout << ans << "\n";
  }

  return 0;
}
