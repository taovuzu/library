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

int x, y, z;

int bfs() {
  if (z > max(x, y)) return -1;
  if (z % __gcd(x, y) != 0) return -1;

  set<pair<int, int>> visited;
  queue<array<int, 3>> q;
  q.push({0, 0, 0});
  visited.insert({0, 0});

  while (!q.empty()) {
    auto [i, j, depth] = q.front();
    q.pop();

    if (i == z || j == z) return depth;

    vector<pair<int, int>> nextStates = {
      {0, j},
      {i, 0},
      {x, j},
      {i, y},
      {max(i - (y - j), 0LL), min(y, j + i)},
      {min(x, i + j), max(0LL, j - (x - i))}
    };

    for (auto [ni, nj] : nextStates) {
      if (!visited.count({ni, nj})) {
        visited.insert({ni, nj});
        q.push({ni, nj, depth + 1});
      }
    }
  }

  return -1;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    cin >> x >> y >> z;

    cout << bfs() << "\n";
  }

  return 0;
}
