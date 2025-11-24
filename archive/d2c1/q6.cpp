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

  while(true){
    string s;
    getline(cin, s);
    if(s=="#") break;
    int sum=0;
    for(auto x:s){
      sum = ((sum<<8) +(int)x )%34943;
    }
    sum = (sum << 16) %34943;
    int crc =0;
    if(sum==0){
      crc=0;
    }
    else{
      crc = 34943-sum;
    }
    cout << setw(2) << setfill('0') << hex << uppercase << (crc >> 8) << " "
    << setw(2) << setfill('0') << hex << uppercase << (crc & 0xFF) << "\n";
  }

  return 0;
}
