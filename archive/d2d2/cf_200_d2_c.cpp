// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv)
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifdef LOCAL
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

void solve() {
  map<string, int> mp;
  map<int, string> mp1;
  int j = 0, w;
  vector<array<int, 5>> a(4, {0, 0, 0, 0, 0});
  for (int i = 0; i < 5; i++) {
    string s0, s1, s2;
    cin >> s0 >> s1 >> s2;
    int x = (s2[0] - '0'), y = (s2[2] - '0');
    if (mp.find(s0) == mp.end()) mp[s0] = j, mp1[j++] = s0;
    if (mp.find(s1) == mp.end()) mp[s1] = j, mp1[j++] = s1;
    a[mp[s0]][0] += (x > y ? 3 : (x == y ? 1 : 0)), a[mp[s0]][1] += x, a[mp[s0]][2] += y, a[mp[s0]][3]++, a[mp[s0]][4] = mp[s0];
    a[mp[s1]][0] += (y > x ? 3 : (x == y ? 1 : 0)), a[mp[s1]][1] += y, a[mp[s1]][2] += x, a[mp[s1]][3]++, a[mp[s1]][4] = mp[s1];
  }
  w = mp["BERLAND"];
  for (int i = 0; i < 4; i++) {
    if (a[i][3] == 2 && mp1[a[i][4]] != "BERLAND") {
      j = a[i][4];
    }
  }

  array<int, 2> ans = {30, 0}, tmp = ans;
  for (int i = 1; i < 30; i++) {
    for (int k = 0; k < i; k++) {
      vector<array<int, 5>> b = a;
      b[w][0] += 3, b[w][1] += i, b[w][2] += k, b[w][3]++;
      b[j][1] += k, b[j][2] += i, b[j][3]++;
      sort(b.begin(), b.end(), [&mp1](auto &x, auto &y){
        if (x[0] == y[0]) {
          if (x[1] - x[2] == y[1] - y[2]) {
            if (x[1] == y[1]) {
              return mp1[x[4]] < mp1[y[4]];
            }
            return x[1] > y[1];
          }
          return x[1] - x[2] > y[1] - y[2];
        }
        return x[0] > y[0];
      });
      if ((b[0][4] == w || b[1][4] == w) && (((i - k) < ans[0] - ans[1]) || ((i - k) == ans[0] - ans[1] && k < ans[1]))) {
          ans = {i, k};
      }
    }
  }
  if (ans == tmp) {
    cout << "IMPOSSIBLE" << "\n";
  }
  else {
    cout << ans[0] << ":" << ans[1] << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
