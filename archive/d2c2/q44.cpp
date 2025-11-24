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

bool isInside(double x, double y, double n){
  double r = (2 * n - 1 ) / 2;
  if((x - n) * (x - n) + (y - n) * (y - n) > r * r) return false;
  x++;
  if(((x - n) * (x - n) + (y - n) * (y - n) > r * r)) return false;
  y++;
  if(((x - n) * (x - n) + (y - n) * (y - n) > r * r)) return false;
  x--;
  if(((x - n) * (x - n) + (y - n) * (y - n) > r * r)) return false;

  return true;
}

bool isBorder(double x , double y, double n){
  double r = (2 * n - 1 ) / 2;
  if((x - n) * (x - n) + (y - n) * (y - n) <= r * r) return true;
  x++;
  if(((x - n) * (x - n) + (y - n) * (y - n) <= r * r)) return true;
  y++;
  if(((x - n) * (x - n) + (y - n) * (y - n) <= r * r)) return true;
  x--;
  if(((x - n) * (x - n) + (y - n) * (y - n) <= r * r)) return true;

  return false;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  bool flag = false;
  while(cin >> n){

    if(flag){
      cout << "\n";
    }

    int inside = 0, border = 0;
    for(int i = 0; i <= 2 * n + 5; i++){
      for(int j = 0; j <= 2 * n + 5; j++){
        if(isInside(i, j, n)) inside++;
        else if(isBorder(i, j, n)) border++;
      }
    }

    cout << "In the case n = " <<  n << ", "<< border << " cells contain segments of the circle." << "\n";
    cout << "There are " << inside <<" cells completely contained in the circle." << "\n";
    flag = true;
  }

  return 0;
}
