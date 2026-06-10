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

int n;

int mex(vector<int> a) {
  sort(a.begin(), a.end());
  int ans = 0;

  for (int i = 0; i < a.size(); i++) {
    if (a[i] > ans) break;
    ans++;
  }

  return ans;
}

int exp(int mid, vector<int> &a){
  int l = mid, r = mid;
  vector<int> b;

  while (l >= 0 && r < n && a[l] == a[r]) {
    b.push_back(a[l]);
    l--, r++;
  }

  return mex(b);
}

int exp1(int l, int r, vector<int> &a) {
  int l1 = l + 1, r1 = r - 1;
  vector<int> b;

  while (l1 <= r1) {
    if (a[l1] != a[r1]) return 0;
    b.push_back(a[l1]);
    l1++, r1--;
  }

  while (l >= 0 && r < n && a[l] == a[r]) {
    b.push_back(a[l]);
    l--, r++;
  }

  return mex(b);
}

void solve() {
  cin >> n;
  n *= 2;
  vector<int> a(n);
  int l = -1, r = -1;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      if (l == -1) l = i;
      else r = i;
    }
  }

  int ans = 1;
  ans = max(ans, exp(l, a));
  ans = max(ans, exp(r, a));
  ans = max(ans, exp1(l, r, a));

  cout << ans << "\n";
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
