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

vector<string> a{"1869", "6198", "1896", "1689", "1986", "1968", "1698"};

void solve() {
  string s;
  cin >> s;

  int n = s.size(), rem = 0;
  vector<int> cnt(10);
  cnt[1] = cnt[6] = cnt[8] = cnt[9] = -1;
  for (int i = 0; i < n; i++) {
    cnt[s[i] - '0']++;
  }
  string ans = "";
  for (int i = 1; i <= 9; i++) {
    for (int j = 0; j < cnt[i]; j++) {
      ans += ('0' + i);
      rem = (i + rem * 10) % 7;
    }
  }

  ans += a[rem];
  for (int j = 0; j < cnt[0]; j++) {
    ans += '0';
  }

  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
