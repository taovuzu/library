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

  int tt=1;  cin>>tt;
  while (tt--) {
    int n, x;
    cin >> n;

    cout << "digit" << endl;
    fflush(stdout);
    cin >> x;
    cout << "digit" << endl;
    fflush(stdout);
    cin >> x;

    cout << "add -8" << endl;
    fflush(stdout);
    cin >> x;

    cout << "add -4" << endl;
    fflush(stdout);
    cin >> x;

    cout << "add -2" << endl;
    fflush(stdout);
    cin >> x;

    cout << "add -1" << endl;
    fflush(stdout);
    cin >> x;

    cout << "add " << n - 1 << endl;
    fflush(stdout);
    cin >> x;

    cout << "!" << endl;
    cin >> x;
    fflush(stdout);
    if(x == -1) return 0;

  }

  return 0;
}