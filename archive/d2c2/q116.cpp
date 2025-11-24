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

const long double EPS = 1e-12;

int comp(long double a, long double b) {
  if(abs(a - b) <= EPS) return 0;
  return a < b ? -1 : 1;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  for(int cc = 1; cc <= tt; cc++) {
    int n;
    cin >> n;

    long double p_esc = 0, t = 0;
    for (int i = 0; i < n; i++) {
      long double x, p;
      cin >> x >> p;
      t += abs(x) * p;
      if(x > 0) p_esc += p;
    }

    cout << "Case " << cc << ": ";
    if(comp(p_esc, 0) == 0)  {
      cout << "God! Save me" << "\n";
    }
    else {
      t /= p_esc;
      cout << fixed << setprecision(2) << t << "\n";
    }
  }

  return 0;
}
