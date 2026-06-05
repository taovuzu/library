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

void solve() {
  int n;
  string s;
  cin >> n >> s;
  set<char> xt;

  for (int i = 0; i < n; i++) {
    xt.insert('a' + i);
  }

  int i = 0, j = s.size() - 1;
  int cnt = 0;

  while (i <= j) {
    if ((s[i] == '?') && (s[j] == '?')) {
      cnt++;
    }
    else if (s[i] == '?') {
      xt.erase(s[j]);
    }
    else if (s[j] == '?') {
      xt.erase(s[i]);
    }
    else if (s[i] != s[j]) {
      cout << "IMPOSSIBLE" << "\n";
      return;
    }
    else {
      xt.erase(s[i]);
    }
    i++, j--;
  }

  
  i = 0, j = s.size() - 1;

  while (i <= j) {
    if ((s[i] == '?') && (s[j] == '?')) {
      char ch = xt.size() < cnt  ? 'a' : *xt.begin();
      if (xt.size() >= cnt) {
        xt.erase(xt.begin());
      }
      s[i] = s[j] = ch;
      cnt--;
    }
    else {
      char ch = s[i] != '?' ? s[i] : s[j];
      s[i] = s[j] = ch;
    }
    i++, j--;
  }

  if (!xt.empty()) {
    cout << "IMPOSSIBLE" << "\n";
  }
  else {
    cout << s << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
