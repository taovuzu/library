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

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(k, 1);
  a.push_back(n);
  if (k > 1) {
    int i = n + 1, j = n + m + 1;
    while (i < j) {
      for (int l = 1; l < k; l++) a.push_back(i);
      i += n - 1;
      if (i < j) a.push_back(i);
      i++;
    }
  }
  else {
    int i = n + (n - 1), j = n + m + 1;
    while (i < j) {
      a.push_back(i);
      i += (n - 1);
    }
  }

  cout << a.size() << "\n";
  for (int l = 0; l < a.size(); l++) {
    cout << a[l] << " ";
  }

  return 0;
}
