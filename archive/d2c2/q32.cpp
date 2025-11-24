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

bool check(string temp){
  return temp.size() == 4 && temp[0] != temp[1] && temp[0] != temp[2] && temp[0] != temp[3] && temp[1] != temp[2] && temp[1] != 
  temp[3] && temp[2] != temp[3] ;
}

bool solve(string temp, string s, int x, int y){
  int cnta = 0, cntb = 0;
  for(int i = 0; i < 4; i++){
    if(temp[i] == s[i]) cnta++;
    for(int j = 0; j < 4; j++){
      if(i == j) continue;
      if(temp[i] == s[j]) cntb++;
    }
  }
  return cnta == x && cntb == y;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector<string> a;
  for(int i = 100; i <= 9999; i++){
    string temp = to_string(i);
    if(i <= 999) temp = '0'+temp;
    if(check(temp)){
      a.push_back(temp);
    }
  }

  int n, cnt = 0;
  cin >> n;
  string ans = "";
  map<string,int> mp;
  bool flag = true;
  for(int i = 0; i < n; i++){
    string s;
    int x, y;
    cin >> s >> x >> y;
    for(int j = 0; j < a.size(); j++){
      if(solve(a[j], s, x, y)){
        mp[a[j]]++;
      }
    }
  }

  for(auto it : mp){
    if(it.second == n){
      flag = false;
      ans = it.first;
      cnt++;
    }
  }
  if(flag){
    cout << "Incorrect data" << "\n";
  }
  else if(cnt > 1){
    cout << "Need more data" << "\n";
  }
  else{
    cout << ans << "\n";
  }

  return 0;
}
