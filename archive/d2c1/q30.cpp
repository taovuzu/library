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

int solve(string s,int n){
  int len = s.size();
  vector<int> a(200,0);
  int maxi=1;
  for(auto it:s){
    a[it-'0']++;
  }
  for(int i=0;i<200;i++){
    maxi=max(a[i],maxi);
  }
  if(n==1 && maxi==len) return maxi-1;
  return min(maxi+n,len);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  string s,s1,s2;
  cin>>n>>s>>s1>>s2;
  int temp = solve(s,n),temp1=solve(s1,n),temp2=solve(s2,n);
  if(temp>temp1 && temp>temp2){
    cout<<"Kuro\n";
  }
  else if(temp1> temp && temp1>temp2){
    cout<<"Shiro\n";
  }
  else if(temp2>temp && temp2>temp1){
    cout<<"Katie\n";
  }
  else{
    cout<<"Draw\n";
  }

  return 0;
}
