// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
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

int mex(int n, vector<int> &a) {
  sort(a.begin(), a.end());
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > j) break;
    else if (a[i] == j) j++;
  }
  return j;
}

void upd(int n, vector<int> &a) {
  int j = mex(n, a);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
      mp[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] > j || mp[a[i]] > 1) a[i] = j;
    else a[i] = a[i];
  }
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  upd(n, a);
  if (k == 1) {
    cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
    return;
  }
  upd(n, a);
  if (k == 2) {
    cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
    return;
  }
  if (k % 2) upd(n, a);
  cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
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
