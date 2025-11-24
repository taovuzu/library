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

int nc2(int n) {
  return (n * (n - 1)) / 2;
}

int nc3(int n) {
  return (n * (n - 1) * (n - 2)) / 6;
}

void solve() {
  int k, n = 0;
  cin >> k;

  vector<vector<char>> a(105, vector<char> (105, '0'));
  while (nc3(n + 1) <= k) n++;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) a[i][j] = a[j][i] = '1';
    }
  }

  k -= nc3(n);
  int j = n;
  while (k > 0) {
    n = 0;
    while (nc2(n + 1) <= k) n++;
    for (int i = 0; i < n; i++) {
      a[i][j] = a[j][i] = '1';
    }
    j++;
    k -= nc2(n);
  }

  cout << 100 << "\n";
  for (int i = 0; i < 100; i++) {
    for (int i_ = 0; i_ < 100; i_++) {
      cout << a[i][i_];
    }
    cout << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
