// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv hr)
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

string s = "RGB";

string rec(int x, int y, int z) {
  string prefix = "";

  while (x + y > z + 1) {
    if ((x + y - z) % 2 == 0) {
      prefix += s[1];
      prefix += s[0];
    } else {
      prefix += s[0];
      prefix += s[1];
    }
    x--;
    y--;
  }

  string ans = "";
  if (x + y + 1 == z || x + y == z) {
    ans += string(x + y + z, s[2]);
    int i = 1;
    while (x) {
      ans[i] = s[0];
      i += 2;
      x--;
    }
    while (y) {
      ans[i] = s[1];
      i += 2;
      y--;
    }
  } else if (x + y - 1 == z) {
    ans += string(x + y + z, s[2]);
    int i = 0;
    while (x) {
      ans[i] = s[0];
      i += 2;
      x--;
    }
    while (y) {
      ans[i] = s[1];
      i += 2;
      y--;
    }
  } else {
    ans += string(2 * (x + y) + 1, s[2]);
    int i = 1;
    while (x) {
      ans[i] = s[0];
      i += 2;
      x--;
    }
    while (y) {
      ans[i] = s[1];
      i += 2;
      y--;
    }
  }

  return prefix + ans;
}

void solve() {
  array<array<int, 2>, 3> a;
  a[0][1] = 0, a[1][1] = 1, a[2][1] = 2;
  cin >> a[0][0] >> a[1][0] >> a[2][0];

  sort(a.begin(), a.end());

  for (int i = 0; i < 3; i++) {
    if (a[i][1] == 0) {
      s[i] = 'R';
    }
    else if (a[i][1] == 1) {
      s[i] = 'G';
    }
    else {
      s[i] = 'B';
    }
  }

  pr(s);

  cout << rec(a[0][0], a[1][0], a[2][0]) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    pr(t_);
    solve();
  }

  return 0;
}
