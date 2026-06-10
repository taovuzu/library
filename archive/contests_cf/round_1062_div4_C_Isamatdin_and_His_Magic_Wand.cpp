// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv)
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

const int maxn = 1300000;
vector<int> primes;

void solve() {
  int n;
  cin >> n;

  int j = 0;
  set<int> xt(primes.begin(), primes.begin() + n + 5);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    xt.erase(a[i]);
  }
  cout << *xt.begin() << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector<bool> a(maxn);
  for (int i = 2; i * i <= maxn; i++) {
    if (a[i]) {
      for (int j = i * i; j < maxn; j += i) {
        a[j] = false;
      }
    }
  }

  for (int i = 2; i < maxn; i++) {
    if (a[i]) {
      prime.push_back(i);
    }
  }

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
