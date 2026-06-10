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

int n, k, x;
vector<int> a(200200);

bool check (int mid) {
  int tmp = k, pos = 0;
  while (pos + mid <= a[0] && tmp > 0) tmp--, pos++;
  for (int i = 0; i < n - 1 && tmp > 0; i++) {
    pos = a[i] + mid;
    while (pos <= a[i + 1] - mid && tmp > 0) tmp--, pos++; 
  }
  pos = a[n - 1] + mid;
  while (pos <= x && tmp > 0) tmp--, pos++;
  return tmp <= 0;
}

void solve() {
  cin >> n >> k >> x;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.begin() + n);

  int lo = 0, hi = 1e9, ans = 0;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (check(mid)) {
      ans = mid;
      lo = mid + 1;
    }
    else {
      hi = mid - 1;
    }
  }

  if (ans == 0) {
    for (int i = 0; i < k; i++) {
      cout << i << " \n"[i == k - 1];
    }
    return;
  }
  int tmp = k, pos = 0;
  while (pos + ans <= a[0] && tmp > 0) {
    cout << pos << " ";
    tmp--; pos++;
  }
  for (int i = 0; i < n  - 1 && tmp > 0; i++) {
    pos = a[i] + ans;
    while (pos <= a[i + 1] - ans && tmp > 0) {
      cout << pos << " ";
      tmp--, pos++; 
    }
  }
  pos = a[n - 1] + ans;
  while (pos <= x && tmp > 0) {
    cout << pos << " ";
    tmp--, pos++;
  }
  cout << "\n";
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
