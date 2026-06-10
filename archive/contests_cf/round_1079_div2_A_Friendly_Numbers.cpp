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

int digitSum(int n) {
  int sum = 0;
  while (n) {
    sum += n % 10;
    n /= 10;
  }

  return sum;
}

void solve() {
  int n;
  cin >> n;

  bool flag = false;
  for (int i = 0; i <= 200; i++) {
    if (n + i - digitSum(n + i) == n) {
      flag = true;
      break;
    }
  }

  if ((n % 9) || !flag) {
    cout << 0 << "\n";
  }
  else {
    cout << 10 << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
