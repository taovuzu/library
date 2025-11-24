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

string s;

vector<__int128> fac(32);

void solve() {
  vector<int> a(26);
  int n = s.size();
  for (int i = 0; i < n; i++) {
    a[s[i] - 'a']++;
  }

  int i = 0, ans = 1;
  while (i < n) {
    for (int j = 0; j < s[i] - 'a'; j++) {
      if (a[j]) {
        __int128 cnt = fac[n - i - 1];
        a[j]--;
        for (int k = 0; k < 26; k++) {
          cnt /= fac[a[k]];
        }
        a[j]++;
        ans += cnt;
      }
    }
    a[s[i] - 'a']--;
    i++;
  }

  cout << right << setw(10) << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  fac[0] = 1;
  for (int i = 1; i <= 30; i++) {
    fac[i] = i * fac[i - 1];
  }

  while (cin >> s && s != "#") {
    solve();
  }

  return 0;
}
