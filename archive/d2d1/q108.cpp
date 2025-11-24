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

void solve() {
  int n, m, from = 2, to = 3, curr = 2;
  cin >> n >> m;

  vector<array<int, 3>> a(m), ans;
  for (int i = 0; i < m; i++) {
    cin >> a[i][0] >> a[i][1];
    a[i][2] = i;
  }

  sort(a.begin(), a.end(), [](auto &x, auto &y){
    if (x[0] == y[0]) return x[1] > y[1];
    return x[0] < y[0];
  });  
  for (int i = 0; i < m; i++) {
    if (a[i][1]) {
      ans.push_back({a[i][2], 1, curr});
      curr++;
    }
    else {
      if (to >= curr) {
        cout << -1;
        return;
      }
      ans.push_back({a[i][2], from, to});
      from++;
      if (from == to) {
        to++;
        from = 2;
      }
    }
  }

  sort(ans.begin(), ans.end());
  for (int i = 0; i < m; i++) {
    cout << ans[i][1] << " " << ans[i][2] << "\n";
  }

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
