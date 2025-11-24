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

int n;

void solve() {
  while (cin >> n && n) {
    vector<int> a;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        a.push_back(i);
        if ((n / i) != i) a.push_back(n / i);
      }
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
      for (int j = i; j < a.size(); j++) {

        int l = (a[i] * a[j]) / __gcd(a[i], a[j]);
        if (l == n) cnt++;
      }
    }

    cout << n << " " << cnt << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
