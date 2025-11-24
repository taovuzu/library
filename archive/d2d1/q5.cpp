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

  multimap<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp.insert({x, i});
  }

  int curr = 0;
  vector<int> ans;
  while (!mp.empty()) {
    if (curr < 0) break;
    auto it = mp.find(curr);
    if (it == mp.end()) {
      curr -= 3;
    }
    else {
      auto [x, y] = *it;
      ans.push_back(y);
      mp.erase(it);
      curr++;
    }
  }

  if (ans.size() != n) {
    cout << "Impossible";
    return 0;
  }

  cout << "Possible" << "\n";
  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << " \n"[i == n - 1];
  }


  return 0;
}
