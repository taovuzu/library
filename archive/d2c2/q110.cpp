// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  vector<array<int, 2>> b;
  int temp = 0;
  for (int i = 1; i < n; i++) {
    if(a[i] != a[i - 1]) {
      b.push_back({temp, i - 1});
      temp = i;
    }
  }
  b.push_back({temp, n - 1});

  pr(b);
  int j = 1;
  while (j < b.size()) {
    if (j + 1 < b.size()) {
      int cnty = b[j + 1][1] - b[j + 1][0] + 1;
      int i = b[j][0], x = a[b[j][0]], y = a[b[j + 1][0]];
      pr(cnty, i, x, y, j, "f");
      while(i < b[j][0] + cnty) {
        a[i++] = y;
      }
      while (i <= b[j + 1][1]) {
        a[i++] = x;
      }
    }
    else {
      int cnty = b[j][1] - b[j][0] + 1;
      int i = b[j - 1][0], x = a[i], y = a[b[j][0]];
      pr(cnty, i, x, y, j, "s");
      while(i < b[j - 1][0] + cnty) {
        a[i++] = y;
      }
      while (i <= b[j][1]) {
        a[i++] = x;
      }
    }
    j += 3;
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }

  return 0;
}
