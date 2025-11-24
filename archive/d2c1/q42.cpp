#include <bits/stdc++.h>

using namespace std;

#define int long long

int w,h,xc,yc,r,x1,x2,y1_,y2;
double theta,d1,d2,s;

bool isInCircle(int i, int j){
  return ((xc-i)*(xc-i)+(yc-j)*(yc-j)) <= r*r;
}

bool isInSquare(int i, int j){
  double X = (i-d1)*cos(theta) + (j-d2)*sin(theta);
  double Y = -(i-d1)*sin(theta) + (j-d2)*cos(theta);
  return max(abs(X),abs(Y))<=(s/2.0);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin>>w>>h>>xc>>yc>>r>>x1>>y1_>>x2>>y2;

  theta = atan2(y2-y1_,x2-x1)-asin(1.0)/2.0;
  d1 = (x1+x2)/2.0;
  d2 = (y1_+y2)/2.0;
  s = sqrtl(((x2-x1)*(x2-x1) + (y2-y1_)*(y2-y1_)) / 2.0);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(isInCircle(j,i) || isInSquare(j,i)){
        cout<<'#';
      }
      else{
        cout<<'.';
      }
    }
    cout<<"\n";
  }

  return 0;
}
