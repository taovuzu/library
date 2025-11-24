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

const long double EPS = 1e-9;
typedef complex<long double> Point;

int cmp(long double x, long double y){
  if(abs(x - y) <= EPS) return 0;
  return x < y ? -1 : 1;
}

class Circle{
  public:
  Point c;
  long double r;

  Circle(){}
  Circle(long double x, long double y, long double rad){
    c = Point(x, y);
    r = rad;
  }
};

long double getLength(Point p0) {
  return hypot(p0.real(), p0.imag());
}

bool CircleIntersects(Circle c0, Circle c1) {
  long double d = getLength(c0.c - c1.c);
  long double plusR = c0.r + c1.r;
  long double minusR = abs(c0.r - c1.r);

  return cmp(plusR, d) == 1 && cmp(d, minusR) == 1;
}

class dsu {
  public:
  int n;
  vector<int> a;
  
  dsu(int _n) : n(_n) {
    a.resize(n);
    iota(a.begin(), a.end(), 0);
  }

  inline int getParent(int x) {
    return x == a[x] ? x : a[x] = getParent(a[x]);
  }

  inline bool unite(int x, int y) {
    x = getParent(x), y = getParent(y);
    if(x == y) return false;
    a[x] = y;
    return true;
  }
};

int getMaxSize(dsu &d) {
  map<int, int> mp;
  
  for(int i = 0; i < d.n; i++){
    int x = d.getParent(i);
    mp[x]++;
  }

  int maxi = 0;
  for(auto [it0, it1] : mp){
    maxi = max(it1, maxi);
  }
  return maxi;
}

int n; 
Circle a[105];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while(cin >> n && n != -1){
    for(int i = 0; i < n; i++){
      long double x, y, r;
      cin >> x >> y >> r;
      a[i] = Circle(x, y, r);
    }

    dsu d(n);
    for(int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if(CircleIntersects(a[i], a[j])) {
          d.unite(i, j);
        }
      }
    }

    int ans = getMaxSize(d);

    cout << "The largest component contains " << ans << " ring" << (ans == 1 ? "":"s") << "." << "\n";
  }

  return 0;
}
