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

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  vector<int> f(n + 1);
  
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    f[a[i]]++;
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] >= 1) f[b[i]]--;
  }

  bool flag = true;
  int j = 0;

  for (int i = 0; i <= n; i++) {
    if (f[i] < 0) flag = false;
    // fix this
    // if (f[i] > 0 && flag) {
    //   while (j < n && b[j] != -1) j++;
    //   if (j < n) b[j] = i;
    //   else flag = false;
    // }
  }

  int sum = 0;
  f.clear();

  pr(flag, sum);

  if (flag) {
      for (int i = 0; i < k; i++) {
        sum -= (f[a[i]] + f[b[i]]);
        f[a[i]]++;
        f[b[i]]--;
        sum += (f[a[i]] + f[b[i]]);
      }
      pr(flag, sum);
      pr(b);
      if (sum > 0) {
        flag = false;
      }
      else {
        for (int i = k; i < n; i++) {
          sum -= (f[a[i - k]] + f[b[i - k]]);
          f[a[i]]++;
          f[b[i]]--;
          sum += (f[a[i]] + f[b[i]]);
          if (sum > 0) {
            flag = false;
          }
          pr(i, flag, sum);
        }
      }
  }

  cout << (flag ? "YES" : "NO") << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt = 1;
  cin >> tt;

  for (int t_ = 1; t_ <= tt; t_++) {
    pr(t_);
    solve();
  }

  return 0;
}
