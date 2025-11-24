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
map<string, string> mp;
vector<string> a(55), b(55), c;
bool flag = false;

bool flagSetter() {
  for (int i = 0; i < c.size(); i++) {
    string s = c[i], s1 = mp[c[i]];
    while (s1 != s) {
      if (s1 == "*") return true;
      if (s1 == "BOB") break;
      s1 = mp[s1];
    }
  }
  return false;
}

bool isCycle(string s) {
  if (s == "BOB") return flag;
  string s1 = mp[s];
  while (s1 != s) {
    if (s1 == "*") return false;
    if (s1 == "BOB") return flag;
    s1 = mp[s1];
  }
  return true;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    mp[a[i]] = b[i];
    if (a[i] == "BOB") {
      if (b[i] == "*") flag = true;
      else c.push_back(b[i]);
    }
  }

  flag = flag || flagSetter();
  flag = (!flag);
  set<string> xt;
  int ans = 0;
  
  for (int i = 0; i < n; i++) {
    if (b[i] == "*") continue;
    else {
      if (isCycle(a[i])) {
        ans = -1;
        break;
      }
      xt.insert(b[i]);
    }
  }

  if (ans == -1) cout << ans << "\n";
  else {
    cout << xt.size() << "\n";
  }


  return 0;
}
