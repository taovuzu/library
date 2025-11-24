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
vector<int> a;

bool solve(int len, int last) {
  if (len == n) return true;
  if (len > n) return false;

  for (int i = len + 1; i > last; i--) {
    a.push_back(i);
    if (solve(len + i, i)) return true;
    a.pop_back();
  }
  return false;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;

  if (solve(0, 0)) {
    vector<char> b(n, '*');
    char ch = 'A';
    for (int i = 0; i < a.size(); i++)  {
      b[--a[i]] = ch;
      ch++;
    }
    int i = 0, j = 0; 
    while (i < n) {
      if (a[j] == 0) j++;
      if (b[i] != '*') {
        i++;
        continue;
      }
      else {
        b[i] = (char)('A' + j);
        a[j]--;
      }
    }

    for (auto it: b) {
      cout << it;
    }
  }
  else {
    cout << "";
  }

  return 0;
}
