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

int n,t;
string s0,s1,s2;

int diff(string s){
    // pr(s);
    vector<int> a(26,-1),b(26,-1);
    for(int i=0;i<s.size();i++){
      a[s[i]-'a']=1;
      b[s2[i]-'a']=1;
    }
    int count=0;
    for(int i=0;i<26;i++){
        if(a[i]==1 && b[i]==-1) count++;
    }
    return count;
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin>>n>>t>>s0>>s1>>s2;
//   pr(s0,s1,s2);
//   pr(diff(s0));
//   pr(diff(s1));

   if(s2=="-1") return 0;
  if(diff(s0)==t && diff(s1)==t){
    return 0;
  }

  return -1;
}
