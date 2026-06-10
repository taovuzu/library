// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv hr)
#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

typedef int tp;
typedef tree<tp,null_type,less_equal<tp>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// tp a;
// T.insert(a), T.erase(a), T.size()
// T.order_of_key(a) -- number of elements strictly less than a
// *T.find_by_order(k) -- k-th element in increasing order
// less_equal<tp> -- change for multiset

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
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int mini = n - 1;
  int sum = 0;

  for (int i = n - 1; i >= 0; i--) {
    if (a[i] >= a[mini]) {
      sum += a[i] - a[mini];
    }
    else {
      mini = i;
    }
    a[i] = a[mini];
  }

  int ans = 0;
  int cnt = 1;
  int i = 1;

  while (i < n) {
    if (a[i] == a[i - 1]) cnt++;
    else cnt = 1;
    ans = max(ans, cnt - 1);
    i++;
  }

  cout << sum + ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt = 1;
  cin >> tt;

  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
