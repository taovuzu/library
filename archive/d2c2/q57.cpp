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

  int n;
  cin >> n;
  cin.ignore();

  string s;
  int counter = 0, activate = -1;
  string excep = "";
  for(int i = 0; i < n; i++){
    getline(cin, s);
    // pr(i, n, s);
    string s1 = "";
    bool flag = false;
    for(auto ch : s){
      if(ch == '\"' && !flag) flag= true;
      else if(ch == '\"' && flag) flag = false;
      if(ch != ' ' || flag ) s1 += ch;
    }
    if (s1 == "") continue;
    // pr(s1, excep);
    if (s1.substr(0, 2) == "tr") {
      counter++;
    }
    else if (s1.substr(0, 2) == "th") {
      for (int j = 6; j + 1 < s1.size(); j++) {
        excep += s1[j];
        activate = counter;
      }
    }
    else {
      // pr(counter, activate);
      if (excep != "" && counter <= activate) {
        string error = "";
        for (int j = 6; s1[j] != ','; j++) {
          error += s1[j];
        }
        if(error == excep){
          // pr(error);
          excep = "";
          string message = "";
          for(int j = error.size() + 8; j + 2 < s1.size(); j++){
            message += s1[j];
          }
          cout << message << "\n";
        }
        else {
          activate--;
        }
      }
      counter--;
    }
  }

  if (excep != "") {
    cout << "Unhandled Exception" << "\n";
  }

  return 0;
}
