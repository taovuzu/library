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

  int tt=1;  cin>>tt;
  while (tt--) {
    int u,v,w,U,V,W;
    cin>>U>>W>>v>>V>>w>>u;
    int X,Y,Z,x,y,z;
    X = (w-U+v)*(U+v+w);
    Y = (u-V+w)*(V+w+u);
    Z = (v-W+u)*(W+u+v);
    x = (U-v+w)*(v-w+U);
    y = (V-w+u)*(w-u+V);
    z = (W-u+v)*(u-v+W);

    long double p,q,r,s;
    p = sqrtl(x*Y*Z);
    q = sqrtl(y*Z*X);
    r = sqrtl(z*X*Y);
    s = sqrtl(x*y*z);
    
    long double ans = sqrtl((-p+q+r+s)*(p-q+r+s)*(p+q-r+s)*(p+q+r-s))/(192*u*v*w);
    cout<<fixed<<setprecision(4)<<ans<<"\n";
  }

  return 0;
}
