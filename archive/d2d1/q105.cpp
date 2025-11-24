// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

void solve(int t_) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }

  int sum = 0, maxi = a[1], x = 1, y = 2, z = 1;
  for (int i = 1; i < n; i++) {
    sum += a[i];
    if (sum > maxi) {
      maxi = sum;
      x = z, y = i + 1;
    }
    else if (sum == maxi && (i - z + 1) > (y - x)) {
      x = z, y = i + 1;
    }
    if (sum < 0) sum = 0, z = i + 1;
  }

  if (maxi <= 0) {
    cout << "Route " << t_ << " has no nice parts" << "\n";
  }
  else {
    cout << "The nicest part of route " << t_ << " is between stops " << x << " and " << y << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve(t_);
  }

  return 0;
}
