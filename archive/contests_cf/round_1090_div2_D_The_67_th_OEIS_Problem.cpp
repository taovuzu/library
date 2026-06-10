// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv hr)
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifdef LOCAL
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

vector<int> primes;

void init() {
  vector<bool> a(200200, true);
  for (int i = 2; i * i < 200200; i++) {
    if (a[i]) {
      for (int j = i * i; j < 200200; j += i) {
        a[j] = false;
      }
    }
  }

  for (int i = 2; i < 200200; i++) {
    if (a[i]) primes.push_back(i);
  }
}

void solve() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cout << (primes[i] * primes[i - 1]) << " ";
  };

  cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt = 1;
  cin >> tt;
  init();

  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
