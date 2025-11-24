// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
// उखँ थाशवफुलपवँ पप फवसजडिऊँ यि लेटीप्चँ यि प फुलेंवळेद्ल् 
// भाशवँ उखँ चतुर्थः प्रश्नः ईवफवुल हवराधपँ नत्वूँ पलफपवुलँ वठउव्षँ प यखयबोप 
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

typedef complex<int> point;

int crossProduct(point p1, point p2) {
  return (conj(p1) * p2).imag();
}

bool findSlope(point p1, point p2, point p3) {
  return crossProduct(p2 - p1, p3 - p1) == 0;
}

const int MAXN = 100100;
int n;
vector<point> a(MAXN);

bool check(int x, int y) {
  vector<point> b;
  for (int i = 0; i < n; i++) {
    if(i == x || i == y) continue;
    if (!findSlope(a[x], a[y], a[i])) {
      b.push_back(a[i]);
    }
  }

  for (int i = 2; i < b.size(); i++) {
    if (!findSlope(b[0], b[1], b[i])) return false;
  }

  return true;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x_, y_;
    cin >> x_ >> y_;
    a[i] = point(x_, y_);
  }

  bool flag = (n <= 4) || check(0, 1) || check(0, 2) || check(1, 2);

  cout << (flag ? "YES" : "NO") << "\n";

  return 0;
}
