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
int n, m, w;
vector<int> a(MAXN), b(MAXN);


bool check(int mid) {
  int left = m, x = 0;
  b[0] = a[0];
  for (int i = 1; i < n; i++) {
    b[i] = a[i] - a[i - 1];
  }

  for (int i = 0; i < n; i++) {
    x += b[i];
    if (x < mid) {
      left -= (mid - x);
      if (left < 0) return false;
      if (i + w < n) b[i + w] -= (mid - x);
      x = mid;
    }
  }
  return true;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> w;
  int lo = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    lo = min(lo, a[i]);
  }

  int hi = lo + m, ans = lo;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (check(mid)) {
      ans = mid;
      lo = mid + 1;
    }
    else {
      hi = mid - 1;
    }
  }

  cout << ans << "\n";

  return 0;
}
