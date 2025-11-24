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

double EPS = 1e-9;

bool isCircle(double x, double y, double r, double c1, double c2){
  return (c1 - x) * (c1 - x) + (c2 - y) * (c2 - y) < r * r;
}

bool isRec(double x, double y, double d1, double d2, double c1, double c2){
  return (x > d1 && x < c1 && y < d2 && y > c2);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector<vector<double>> a;
  while(true){
    char ch;
    cin >> ch;

    if(ch == '*') break;
    else if(ch == 'c') {
      double r, x, y;
      cin >> x >> y >> r;
      a.push_back({r, x, y});
    }
    else {
      double x, y, x1, y1;
      cin >> x >> y >> x1 >> y1;
      a.push_back({x, y, x1, y1});
    }

  }

  double x, y;
  int n = a.size(), point = 0;

  while(cin >> x >> y){
    if( (fabs(9999.9 - x) <= EPS) && (fabs(9999.9 - y) <= EPS)) break;

    bool flag = false;
    point++;

    for(int i = 0; i < n; i++){
      if(a[i].size() == 3 && isCircle(x, y, a[i][0], a[i][1], a[i][2])){
        cout << "Point " << point <<" is contained in figure " << (i + 1) << "\n";
        flag = true;
      }
      else if(a[i].size() == 4 && isRec(x, y, a[i][0], a[i][1], a[i][2], a[i][3])){
        cout << "Point " << point <<" is contained in figure " << (i + 1) << "\n";
        flag= true;
      }
    }
    
    if(!flag){
      cout << "Point " << point <<" is not contained in any figure" << "\n";
    }
  }

  return 0;
}
