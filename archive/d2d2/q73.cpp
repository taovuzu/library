// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv)
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define oo 1000000000

#ifdef LOCAL
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
    int N = desiredColor.size();
    int cost[N + 1];
    int a[N];
    //convert character to int for convenience
    for (int i = 0; i < N; i++) {
      char c = desiredColor[i];
      if (c == '*') a[i] = 7;
      if (c == 'R') a[i] = 1;
      if (c == 'G') a[i] = 2;
      if (c == 'B') a[i] = 4;
    }

    int res = oo;
    //try all the posibility of length of the stamp
    for (int len = 1; len <= N; len++) {
      cost[0] = 0;
      //dynamic program for the minimum cost
      for (int i = 1; i <= N; i++) cost[i] = oo;

      for (int i = 0; i < N; i++) {
        //with each position i, we try to paint until the furthest position j as long as we can use just 1 color
        int color = 7;
        for (int j = i; j < N; j++) {
          color &= a[j];
          if (!color) break;
          int seg = j - i + 1;
          if (seg < len) continue;
          if (cost[i] != oo) {
            cost[j + 1] = min(cost[j + 1], cost[i] + ((seg + len - 1) / len) * pushCost);
          }
        }
      }
      if (cost[N] != oo) {
        res = min(res, cost[N] + stampCost * len);
      }
    }

    return res;
  }

void solve() {
  string s;
  int x, y, n;
  cin >> s >> x >> y;

  cout << getMinimumCost(s, x, y) << "\n";  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
