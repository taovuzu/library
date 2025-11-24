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

  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m + 1, vector<int> (2));
  vector<vector<vector<int>>> b(n + 1);
  for(int i = 1; i <= m; i++){
    cin >> a[i][0] >> a[i][1];
    sort(a[i].begin(),a[i].end());
  }

  sort(a.begin(), a.end());

  for(int i = 1; i <= m; i++){
    b[a[i][0]].push_back({i, a[i][0]});
    b[a[i][1]].push_back({i, a[i][1]});
  }

  int cnt = m + 1;
  for(int i = 1; i <= n; i++){
    if(b[i].empty()){
      b[i].push_back({cnt++,i});
    }
  }

  for(int i = 1; i <= n; i++){
    cout << b[i].size() << "\n";
    for(int j = 0; j < b[i].size(); j++){
      cout << b[i][j][0] << " " << b[i][j][1] << "\n";
    }
  }


  return 0;
}
