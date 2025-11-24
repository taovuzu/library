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

  int elly = a[0];
  sort(a.rbegin(), a.rend());
  int r = (n + 19) / 20;
  int g = (n + r - 1) / r;
  int pos = 0;
  for (int i = 0; i < n; i++) {
    if(a[i] == elly) {
      pos = i;
      break;
    }
  }

  int er = pos / r, cnt = 1;
  long double ans = elly;
  for (int i = 0; i < g; i++) {
    if (i == er) continue;
    int start = i * r;
    int end   = min(n, (i + 1) * r);
    for (int j = start; j < end; j++) {
        ans += a[j];
        cnt++;
    }
  }


  ans /= cnt;
  cout << fixed << setprecision(12) << ans << "\n";

  return 0;
}
