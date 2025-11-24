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
int a[MAXN], dp[MAXN];
int n;

bool solve(int i) {
  if (dp[i] != -1) return dp[i];

  bool ans = false;
  int pos = a[i];
  while (pos + i < n) {
    if (ans) break;
    if (a[pos + i] > a[i]) {
      if (!solve(pos + i)) {
        ans = true;
      }
    }
    pos += a[i];
  }

  pos = a[i];
  while (i - pos >= 0) {
    if (ans) break;
    if (a[i - pos] > a[i]) {
      if (!solve(i - pos)) {
        ans = true;
      }
    }
    pos += a[i];
  }

  return dp[i] = ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[i] = -1;
  }

  for (int i = 0; i < n; i++) {
    if (solve(i)) {
      cout << "A";
    }
    else {
      cout << "B";
    }
  }

  return 0;
}
