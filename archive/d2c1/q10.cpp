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
int dp[100100][2];
vector<int> a(100100);
vector<string> b(100100);

int canWeSort(int i,int pos){    // pos=0, if i normal  else if i reverse pos=1
  string s = b[i], s1 = b[i-1];
  if(pos) reverse(s.begin(),s.end());
  int ans=LLONG_MAX;
  if(s1<=s){
    ans=dp[i-1][0];
  }
  reverse(s1.begin(),s1.end());
  if(s1<=s){
    ans=min(ans,dp[i-1][1]);
  }
  if(pos && ans!=LLONG_MAX){
    ans+=a[i];
  }
  // pr(i,pos,ans);
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    cin>>b[i];
  }

  dp[0][0]=0;
  dp[0][1]=a[0];
  for(int i=1;i<n;i++){
    dp[i][0] = canWeSort(i,0);
    dp[i][1] = canWeSort(i,1);
  }

  int ans = min(dp[n-1][0],dp[n-1][1]);
  if(ans==LLONG_MAX) ans = -1;
  cout<<ans<<"\n";

  return 0;
}
