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

map<array<int, 2>, int> mp;

int par(int u, int v) {
  if (v == u) return u;
  if (v > u) return par(v, u);
  return par(u / 2, v);
}

void updater(int u, int par, int w) {
  while(u > par) {
    mp[{u,u / 2}] += w;
    u /= 2;
  }
  while (u < par) {
    mp[{u, u * 2}] += w;
    u *= 2;
  }
}

int coster(int u, int par) {
  int cost = 0;
  while(u > par) {
    cost += mp[{u, u / 2}];
    u /= 2;
  }
  while (u < par) {
    cost += mp[{u, u * 2}];
    u *= 2;
  }
  return cost;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int q;
  cin >> q;
  while (q--) {
    int t, u, v, w;
    cin >> t >> u >> v;
    int x = par(u, v);
    if (t == 1) {
      cin >> w;
      updater(u, x, w);
      updater(v, x, w);
    }
    else {
      cout << coster(u, x) + coster(v, x) << "\n";
    }

  }

  return 0;
}
