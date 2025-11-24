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

map<pair<int,string>,int> mp;
string s;

bool isPali(string &x){
  int i=0,j=x.size()-1;
  while (i<j)
  {
    if(x[i]!=x[j]) return false;
    i++,j--;
  }
  return true;
}

int solve(int i,string x){
  if(i==s.size()){
    return isPali(x);
  }
  if(mp.find(make_pair(i,x))!=mp.end()) return mp[make_pair(i,x)];

  int take = solve(i+1,x+s[i]);
  int notTake = solve(i+1,x);

  return mp[make_pair(i,x)]=(take+notTake);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    cin>>s;
    mp.clear();
    cout<<solve(0,"")-1<<"\n";
  }

  return 0;
}
