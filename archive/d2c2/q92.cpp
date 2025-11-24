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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 0;
  string s;
  while (getline(cin, s)) {
    ++tt;
    vector<string> a, b;
    string word = "";
    for(int i = 0; i < s.size(); i++) {
      if (!((s[i] <= 'Z' && s[i] >= 'A') || (s[i] <= 'z' && s[i] >= 'a') ||
      (s[i] >= '0' && s[i] <= '9'))) {
        if (word != "") {
          a.push_back(word);
        }
        word = "";
      }
      else word += s[i];
    }
    if (word != "") a.push_back(word);

    getline(cin, s);
    word = "";
    for(int i = 0; i < s.size(); i++) {
      if (!((s[i] <= 'Z' && s[i] >= 'A') || (s[i] <= 'z' && s[i] >= 'a') ||
           (s[i] >= '0' && s[i] <= '9'))) {
        if (word != "") {
          b.push_back(word);
        }
        word = "";
      }
      else word += s[i];
    }
    if (word != "") b.push_back(word);

    if (!(a.empty() || b.empty())) {
      int n = a.size(), m = b.size();
      vector<vector<int>> dp(n, vector<int> (m, 0));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (a[i] == b[j]) {
            dp[i][j] = (i > 0 && j > 0) ? dp[i-1][j-1] + 1 : 1;
          } else {
            dp[i][j] = max(i > 0 ? dp[i-1][j] : 0, j > 0 ? dp[i][j-1] : 0);
          }
        }
      }      
      cout <<  setw(2) << tt << ". " << "Length of longest match: " << dp[n - 1][m - 1] << "\n";
    }
    else {
      cout <<  setw(2) << tt << ". " << "Blank!" << "\n";
    }

  }

  return 0;
}
