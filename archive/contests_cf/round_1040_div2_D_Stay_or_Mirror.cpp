// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

typedef int tp;
typedef tree<tp,null_type,less<tp>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// tp a;
// T.insert(a), T.erase(a), T.size()
// T.order_of_key(a) -- number of elements strictly less than a
// *T.find_by_order(k) -- k-th element in increasing order

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  pbds T, T1;
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    T.insert(a[i]);
    b[i] = (i - T.order_of_key(a[i]));
  }
  for (int i = n - 1; i >= 0; i--) {
    T1.insert(a[i]);
    int x = (n - 1 - i - T1.order_of_key(a[i]));
    b[i] = min(x, b[i]);
  }

  cout << accumulate(b.begin(), b.end(), 0LL) << "\n";
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
