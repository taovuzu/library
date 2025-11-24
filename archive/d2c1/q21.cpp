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

long long binpow(long long a, long long b, long long m = 0) {
  long long res = 1;
  if (m != 0)
    a %= m;
  while (b > 0)
  {
    if (b & 1) {
      res = m ? (res * a % m) : (res * a);
    }
    a = m ? (a * a % m) : (a * a);
    b >>= 1;
  }
  return res;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  while(true){
    int num=1,last=-1,n;
    while (cin >> n) {
      if (n == 0) {
          return 0;
      }
      if(last!=-1){
        num*=(binpow(last,n));
        last=-1;
      }
      else last = n;
      if (cin.peek() == '\n') break; 
    }
    num--;
    map<int,int> mp;
    for(int i=2;i*i<=num;i++){
      while(num%i==0){
        mp[i]++;
        num/=i;
      }
    }
    if(num>1) mp[num]++;
    for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
      cout << it->first << " " << it->second;
      auto it2=it;
      it2++;
      if(it2!=mp.rend()) cout<<" ";
    }
    cout<<"\n";
  }

  return 0;
}
