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

int n;
int dp[55];
int backptr[55];

int solve(int idx, vector<string>& a, string &s) {
  if (idx >= s.size()) return 1;
  if (dp[idx] != -1) return dp[idx];
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s.substr(idx, a[i].size()) == a[i]) {
     int x = solve(idx + a[i].size(), a, s);
     cnt += x;
     if (cnt > 2) break;
     if (x) backptr[idx] = i;
    }
  }
  return dp[idx] = cnt;
}

void printer(int idx, vector<string>& a, string &s) {
  if (idx >= s.size()) return;
  if (backptr[idx] != -1) {
    cout << a[backptr[idx]] << " ";
    printer(idx + a[backptr[idx]].size(),a, s);
  }
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;

  for (int i = 0; i < 55; i++) dp[i] = -1;
  int cnt = solve(0, a, s);

  if (cnt == 0) cout << "IMPOSSIBLE!" << "\n";
  else if (cnt >= 2) cout << "AMBIGUOS!" << "\n";
  else {
    printer(0, a, s);
  }


  return 0;
}
