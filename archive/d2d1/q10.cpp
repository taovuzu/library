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

int n, k;
int par[100100];
array<int, 2> a[100100];

bool solve() {
  for (int i = 0; i < n; i++) a[i][1] = i;
  sort(a, a + n);

  int j = 0, deg = -1;
  par[a[0][1]] = -1;
  if (a[0][0] != 0) return false;
  if (k == 1) {
    if (n == 2) {
      if (a[1][0] == 1) par[a[1][1]] = a[0][1];
      else return false;
    }
    else return false;
  }
  else {
    for (int i = 1; i < n; i++) {
      while (j < i && a[j][0] + 1 < a[i][0]) j++, deg = 0;
      if(a[j][0] + 1 != a[i][0]) return false;
      par[a[i][1]] = a[j][1];
      deg++;
      if(deg ==  k - 1) {
        j++;
        deg = 0;
      }
    }
  }
  return true;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> a[i][0];
  }

  if (solve()) {
    cout << n - 1 << "\n";
    for (int i = 0; i < n; i++) {
      if (par[i] != -1) {
        cout << i + 1 << " " << par[i] + 1 << "\n";
      }
    }
  }
  else {
    cout << -1;
  }

  return 0;
}
