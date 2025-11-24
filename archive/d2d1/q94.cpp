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
  int n, d, a, b, x, y;
  cin >> n >> d >> a >> b;
  vector<array<int, 2>> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    arr[i] = {x * a + y * b, i + 1};
  }
  sort(arr.begin(), arr.end());
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (d < arr[i][0]) break;
    d -= arr[i][0];
    ans.push_back(arr[i][1]);
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " \n"[i == ans.size() - 1];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
