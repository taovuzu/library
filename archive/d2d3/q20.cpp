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

bool isValid(string s) {
  vector<char> stk;

  for (auto ch : s) {
    if (ch == '(') stk.push_back(ch);
    else {
      if (stk.empty()) return false;
      stk.pop_back();
    }
  }

  return stk.empty();
}

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int last = -1, cnt = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == '(') cnt++;
    else cnt--;
    if (s[i] == '#') last = i;
  }

  string ans = "";
  int tmp = cnt;

  for (int i = 0; i < n; i++) {
    if (s[i] == '#') {
      ans.push_back(')');
      while (i == last && tmp > 0) {
        tmp--;
        ans.push_back(')');
      }
    }
    else ans.push_back(s[i]);
  }

  if (!isValid(ans)) {
    cout << -1 << "\n";
    return;
  }

  for (int i = 0; i < n; i++) {
    if (s[i] == '#') {
      cout << (i == last ? cnt + 1 : 1) << "\n";
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
