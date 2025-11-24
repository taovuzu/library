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

  vector<array<int,2>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0];
    a[i][1] = i + 1;
  }

  sort(a.begin(), a.end());
  int cnt = 0, x , y , z , w;
  for(int i = 0; i < n - 1; i++) {
    if(a[i][0] == a[i + 1][0] && cnt == 0) {
      x = i;
      y = i + 1;
      i++;
      cnt += 2;
    }
    if(a[i][0] == a[i + 1][0] && cnt == 2) {
      w = i;
      z = i + 1;
      i++;
      cnt += 2;
    }
  }

  if (cnt < 3) {
    cout << "NO" << "\n";
    return 0;
  }

  cnt = 0;
  cout << "YES" << "\n";
  for (int i = 0; i < n; i++) {
    cout << a[i][1] << " \n"[i == n - 1];
  }
  swap(a[w],a[z]);
  for (int i = 0; i < n; i++) {
    cout << a[i][1] << " \n"[i == n - 1];
  }
  swap(a[x], a[y]);
  for (int i = 0; i < n; i++) {
    cout << a[i][1] << " \n"[i == n - 1];
  }

  return 0;
}
