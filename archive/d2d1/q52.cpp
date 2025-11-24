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
vector<int> a(100100);

bool check(int mid) {
  int l = 0, r = 0, curr = 0, tot = 0;
  while (l < n) {
    r = max(l, r);
    if (a[l] > mid) {
      curr = 0;
      l++;
      continue;
    }
    while (r < n && curr + a[r] <= mid) {
      curr += a[r++];
    }
    if (curr <= mid) tot += (r - l);
    curr -= a[l++];
  }
  return tot >= k;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int lo = 1, hi = 1e14, ans = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (check(mid)) {
      ans = mid;
      hi = mid - 1;
    }
    else lo = mid + 1;
  }

  cout << ans << "\n";

  return 0;
}
