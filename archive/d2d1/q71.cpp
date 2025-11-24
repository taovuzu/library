// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
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

string seq = "";
vector<int> a(33001);

void build() {
  a[0] = 0;
  int totalLen = 0;
  for (int i = 1; i <= 33000; i++) {
    int len = (int)log10(i) + 1;
    seq += to_string(i);
    totalLen += len;
    a[i] = a[i - 1] + totalLen;
  }
}

void findNum(int x) {
  int lo = 0, hi = 33000, ans = 0;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] < x) {
      ans = mid;
      lo = mid + 1;
    }
    else hi = mid - 1;
  }
  cout << seq[x - a[ans] - 1] << "\n";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  build();

  int tt = 1;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    findNum(x);
  }

  return 0;
}
