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

vector<bool> temp(1005, 1);

void sieve(){
  temp[0] = temp[1] = 0;
  for(int i = 2; i <= 1000; i++){
    if(temp[i]){
      for(int j = i * i; j <= 1000; j += i){
        temp[j] = 0;
      }
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;

  sieve();

  int n = s.size();
  vector<int> a(26, 0);
  for(int i = 0; i < n; i++){
    a[s[i] - 'a']++;
  }

  int count = n - 1;
  for(int i = 2; i <= n; i++){
    if(temp[i] && i * 2 > n) count--;
  }

  int maxi = max_element(a.begin(), a.end()) - a.begin();
  sort(s.begin(), s.end(), [&a](char ch, char ch1){
    return a[ch - 'a'] > a[ch1 - 'a'];
  });

  if(a[maxi] >= count){
    cout << "YES" << "\n";

    cout << s[n - 1];
    int i = 0, j = n - 2 , k = 2;
    while(i <= j){
      if(temp[k] && k * 2 > n){
        cout << s[j];
        j--;
      }
      else {
        cout << s[i];
        i++;
      }
      k++;
    }
  }
  else {
    cout << "NO";
  }

  return 0;
}
