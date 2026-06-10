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

void solve() {
  int n;
  cin >> n;

  vector a(2, vector<int> (n));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  vector<int> preMin(n), preMax(n), suffMin(n), suffMax(n), b(2 * n + 1, 2 * n + 1);
  for (int i = 0; i < n; i++) {
    preMin[i] = preMax[i] = a[0][i];
    if (i) {
      preMin[i] = min(preMin[i], preMin[i - 1]);
      preMax[i] = max(preMax[i], preMax[i - 1]);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    suffMin[i] = suffMax[i] = a[1][i];
    if (i != n - 1) {
      suffMin[i] = min(suffMin[i], suffMin[i + 1]);
      suffMax[i] = max(suffMax[i], suffMax[i + 1]);
    }
  }

  for (int i = 0; i < n; i++) {
    int mini = min(preMin[i], suffMin[i]), maxi = max(suffMax[i], preMax[i]);
    b[mini] = min(b[mini], maxi);
  }
  for (int i = 2 * n - 1; i >= 1; i--) {
    b[i] = min(b[i], b[i + 1]);
  }

  int ans = 0;
  for (int i = 1; i <= 2 * n; i++) {
    ans += (2 * n + 1 - b[i]);
  }

  cout << ans << "\n";
  
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
