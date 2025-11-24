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

long double EPS = 1e-9;

int comp(long double x, long double y) {
  if (abs(x - y) < EPS) return 0;
  return x < y ? -1 : 1;
}

class dsu {
public:
  int n;
  vector<int> a;

  dsu(int _n) : n(_n) {
    a.resize(n);
    iota(a.begin(), a.end(), 0);
  }

  inline int getpar(int x) {
    return x == a[x] ? x : (a[x] = getpar(a[x]));
  }

  inline bool unite(int x, int y) {
    x = getpar(x), y = getpar(y);
    if (x == y) return false;
    else a[x] = y;
    return true;
  }
};

vector<array<long double, 4>> a(15);

bool onSegment(long double x1, long double y1, long double x2, long double y2, long double x, long double y) {
  return min(x1, x2) - EPS <= x && x <= max(x1, x2) + EPS &&
         min(y1, y2) - EPS <= y && y <= max(y1, y2) + EPS;
}

bool checkIntersect(int i, int j) {
  long double x1 = a[i][0], y1 = a[i][1], x2 = a[i][2], y2 = a[i][3];
  long double x3 = a[j][0], y3 = a[j][1], x4 = a[j][2], y4 = a[j][3];

  long double det = (x2 - x1) * (y3 - y4) - (y2 - y1) * (x3 - x4);
  if (comp(det, 0) == 0) {
    if (comp((x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1), 0) != 0) return false;

    if (onSegment(x1, y1, x2, y2, x3, y3) || onSegment(x1, y1, x2, y2, x4, y4) ||
        onSegment(x3, y3, x4, y4, x1, y1) || onSegment(x3, y3, x4, y4, x2, y2)) {
      return true;
    }
    return false;
  }

  long double detx = (x3 - x1) * (y3 - y4) - (y3 - y1) * (x3 - x4);
  long double dety = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

  long double t1 = detx / det;
  long double t2 = dety / det;

  if (comp(t1, 0) == -1 || comp(t1, 1) == 1 || comp(t2, 0) == -1 || comp(t2, 1) == 1)
    return false;

  return true;
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1;
  cin >> tt;

  while (tt--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    }

    dsu d(n);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (checkIntersect(i, j)) {
          d.unite(i, j);
        }
      }
    }

    int x, y;
    while (cin >> x >> y) {
      if (x == 0 && y == 0) break;
      if (d.getpar(x - 1) == d.getpar(y - 1)) {
        cout << "CONNECTED" << "\n";
      } else {
        cout << "NOT CONNECTED" << "\n";
      }
    }

    if (tt) cout << "\n";
  }

  return 0;
}