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
  string s1, s = "", ans = "";
  while (getline(cin, s1)) {
    if (s1 == "") break;
    s += s1;
  }
  stack<char> st;
  for (auto ch : s) {
    if (ch == ')') {
      while (st.top() != '(') {
        ans += st.top();
        st.pop();
      }
      st.pop();
    }
    else if (ch == '(') {
      st.push('(');
    }
    else if (ch == '+' || ch == '-') {
      while (!st.empty() && (st.top() != '(')) {
        ans += st.top();
        st.pop();
      }
      st.push(ch);
    }
    else if (ch == '*' || ch == '/') {
      while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
        ans += st.top();
        st.pop();
      }
      st.push(ch);
    }
    else ans += ch;
  }
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  cin.ignore(); cin.ignore();
  for (int t_ = 1; t_ <= tt; t_++) {
    if(t_ != 1) cout << "\n";
    solve();
  }

  return 0;
}
