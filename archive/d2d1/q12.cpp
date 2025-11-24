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

const int mod = 1e9 + 9;
int a[1005], b[1005];

void rec(int n, int k) {
  if (n == 0) return 0;
  if (k == 0) return 1;
  return 
}

void factors(int n) {
  for (int i = 2; i <= n; i++) {
    int temp = i;
    for (int j = 2; j <= temp; j++) {
      int cnt = 0;
      while (temp % j == 0) {
        cnt++;
        temp /= j;
      }
      b[j] = (b[j] + (cnt * a[i]) % mod) % mod;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;

  rec(n, k);
  factors(max(n, k));
  int ans = 1;
  for (int i = 2; i <= n; i++) {
    ans = (ans * (b[i] + 1)) % mod;
  }

  cout << ans << "\n";

  return 0;
}
