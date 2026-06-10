// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
// उखँ थाशवफुलपवँ पप फवसजडिऊँ यि लेटीप्चँ यि प फुलेंवळेद्ल् 
// भाशवँ उखँ चतुर्थः प्रश्नः ईवफवुल हवराधपँ नत्वूँ पलफपवुलँ वठउव्षँ प यखयबोप 
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
  int n;
  cin >> n;

  vector<array<int, 3>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    a[i][2] = i + 1;
  }
  
  sort(a.begin(), a.end(), [](auto x, auto y){
    if (x[0] == y[0]) return x[1] < y[1];
    return x[0] < y[0];
  });
  
  int i = 0, j = n - 1;
  while (i < j) {
    cout << a[i][2] << " " << a[j][2] << "\n";
    i++, j--;
  }
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
