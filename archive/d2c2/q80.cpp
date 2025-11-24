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

const int MAXN = 100100;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  int j = 0, t, _j = 0;
  vector<int> a(MAXN), b(MAXN, 0), c(MAXN), d(MAXN);
  for (int i = 0; i < n; i++) {
    cin >> t;
    if( t == 1) {
      cin >> c[i];
      if (j < MAXN) {
        a[j++] = c[i];
      }
      _j++;
    }
    else {
      cin >> b[i] >> c[i];
      _j += b[i] * c[i];
      for (int k = 0; j < MAXN && k < c[i]; k++) {
        for (int _i = 0; _i < b[i] && j < MAXN; _i++) {
          a[j++] = a[_i];
        }
      }
    }

    d[i] = _j;
  }

  int q;
  j = 0;
  cin >> q;

  for(int i = 0; i < q; i++) {
    int x;
    cin >> x;
    x--;

    if (x < MAXN) {
      cout << a[x] << " ";
    }
    else {
      while (d[j] <= x) {
        j++;
      }
      if (b[j] == 0) {
        cout << c[j] << " ";
      }
      else {
        cout << a[(x - d[j - 1]) % (b[j])] << " ";
      }
    }
  }

  return 0;
}