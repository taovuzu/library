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
int a[1005], b[1005];
int n;

int solveC(int i,  vector<vector<int>> c) {
  pr(i, "Column");
  int cost = 0;
  if(i == 2) {
    bool flag = false;
    for(int j = 0; j < n; j++) {
      if(c[j][0] == c[j][1]) {
        flag = true;
        break;
      }
    }
    if(flag) {
      cost += b[0];
      for(int j = 0; j < n; j++){
        c[j][0]++;
        if(c[j][0] == c[j][1]) {
          pr(j);
          return 1e18;
        }
      } 
    }
  }
  pr("ok");
  for(; i < n; i++) {
    bool flag = false;
    for(int j = 0; j < n; j++) {
      if(c[j][i] == c[j][i - 1]) {
        flag = true;
        break;
      }
    }
    if(flag) {
      cost += b[i];
      for(int j = 0; j < n; j++){
        c[j][i]++;
        if(c[j][i] == c[j][i - 1]) {
          pr(i, j, c[j][i]);
          return 1e18;
        }
      } 
    }
  }
  pr(cost);
  debmat(c, n, n);
  return cost;
}


int solveR(int i,  vector<vector<int>> c) {
  pr(i, "Row");
  int cost = 0;

  if (i == 2) {
    bool flag = false;
    for(int j = 0; j < n; j++) {
      if(c[0][j] == c[1][j]) {
        flag = true;
        break;
      }
    }
    if(flag) {
      cost += a[0];
      for(int j = 0; j < n; j++) {
        c[0][j]++;
        if (c[0][j] == c[1][j]) {
          pr(j, c[0][j]);
          return 1e18;
        }
      }
    }
  }
  pr("ok");
  for(; i < n; i++) {
    bool flag = false;
    for(int j = 0; j < n; j++) {
      if(c[i][j] == c[i - 1][j]) {
        flag = true;
        break;
      }
    }
    if(flag) {
      cost += a[i];
      for(int j = 0; j < n; j++) {
        c[i][j]++;
        if (c[i][j] == c[i - 1][j]) {
          pr(i, j, c[i][j]);
          return 1e18;
        }
      }
    }
  }
  pr(cost);
  debmat(c, n, n);
  return cost;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;  cin>>tt;
  while (tt--) {
    cin >> n;
    
    vector<vector<int>> c(n + 5, vector<int> (n + 5));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cin >> c[i][j];
      }
    }
    
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
      cin >> b[i];
    }

    pr(tt);
    int cost = min({solveR(1, c) + solveC(1, c), solveR(2, c) + solveC(1, c), 
                    solveR(1, c) + solveC(2, c), solveR(2, c) + solveC(2, c)});

    if(cost >= 1e18) cost = -1;

    cout << cost << "\n";
  }

  return 0;
}  