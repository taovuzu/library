// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
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

void solve() {
  int n;
  cin >> n;
  string s = "", s1, s2;
  int i = 1, j = 1;
  while (s.size() < n - 1) {
    cout << "? " << i + 1 << " " << j << " " << n  << " " << n << endl;
    cout.flush();
    cin >> s2;
    if (s2 == "YES") {
      s += "D";
      i++;
    }
    else {
      s += "R";
      j++;
    }
  }
  i = n, j = n;
  while (s1.size() < n - 1) {
    cout << "? " << 1 << " " << 1 << " " << i  << " " << j - 1 << endl;
    cout.flush();
    cin >> s2;
    if (s2 == "YES") {
      s1 += "R";
      j--;
    }
    else {
      s1 += "D";
      i--;
    }
  }
  reverse(s1.begin(), s1.end());
  s += s1;
  cout << "! " << s << endl;
  cout.flush();
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
