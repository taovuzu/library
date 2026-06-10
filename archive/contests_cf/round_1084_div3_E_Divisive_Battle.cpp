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

const int maxn = 1001001;
int primes[maxn + 5];

void init() {
  primes[0] = primes[1] = 1;

  for (int i = 2; i < maxn; i++) {
    if (primes[i]) continue;
    primes[i] = i;
    for (int j = i * i; j <= maxn; j += i) {
      primes[j] = i;
    }
  }
}

int spf(int x) {
  set<int> xt;
  
  do {
    xt.insert(primes[x]);
    pr('*', x, primes[x]);
    x /= primes[x];
  } while (x > 1);

  pr(x, xt);

  if (xt.size() >= 2) return -1;
  return *xt.begin();
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  if (is_sorted(a.begin(), a.end())) {
    cout << "Bob" << "\n";
    return;
  }

  vector<int> b;
  for (int i = 0; i < n; i++) {
    int x = spf(a[i]);
    b.push_back(x);
    if (x == -1) {
      cout << "Alice" << "\n";
      return;
    }
  }

  if (is_sorted(b.begin(), b.end())) {
    cout << "Bob" << "\n";
  }
  else {
    cout << "Alice" << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  init();

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
