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
string s;
int n;

int check(){
  int len=1;
  char last=s[0];
  for(int i=1;i<n;i++){
    if(s[i]!=last){
      len++;
      last=s[i];
    }
  }
  return len;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin>>n>>s;
  int ans = check(),first=0,last=n-1;
  for(int i=1;i<n;i++){
    if(s[i]==s[i-1] && s[i]=='0'){
      first=i;
      break;
    }
  }
  for(int i=n-1;i>=1;i--){
    if(s[i]==s[i-1] && s[i]=='0'){
      last=i;
      break;
    }
  }
  for(int i=first;i<last;i++){
    s[i]=s[i]=='0'?'1':'0';
  }
  ans = max(ans,check());
  for(int i=first;i<last;i++){
    s[i]=s[i]=='0'?'1':'0';
  }
  first=0,last=n-1;
  for(int i=1;i<n;i++){
    if(s[i]==s[i-1] && s[i]=='1'){
      first=i;
      break;
    }
  }
  for(int i=n-1;i>=1;i--){
    if(s[i]==s[i-1] && s[i]=='1'){
      last=i;
      break;
    }
  }
  for(int i=first;i<last;i++){
    s[i]=s[i]=='0'?'1':'0';
  }
  ans = max(ans,check());
  for(int i=first;i<last;i++){
    s[i]=s[i]=='0'?'1':'0';
  }

  first=0,last=n-1;
  for(int i=1;i<n;i++){
    if(s[i]==s[i-1] ){
      first=i;
      break;
    }
  }
  for(int i=n-1;i>=1;i--){
    if(s[i]==s[i-1] ){
      last=i;
      break;
    }
  }
  for(int i=first;i<last;i++){
    s[i]=s[i]=='0'?'1':'0';
  }
  ans = max(ans,check());
  for(int i=first;i<last;i++){
    s[i]=s[i]=='0'?'1':'0';
  }
  for(int i=1;i+1<n;i++){
    if(s[i]==s[i-1] && s[i]==s[i+1]){
      s[i]=s[i]=='0'?'1':'0';
      break;
    }
  }
  ans = max(ans,check());


  cout<<ans<<"\n";

  return 0;
}
