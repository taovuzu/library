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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int n, tt = 0;
  while (cin >> n) {
    vector<vector<int>> mat(35, vector<int> (35));
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        mat[u][v] = 1;
        maxi = max({u, v, maxi});
    }

    for (int k = 0; k <= maxi; k++) {
      for (int i = 0; i <= maxi; i++) {
        for (int j = 0; j <= maxi; j++) {
          mat[i][j] += mat[i][k] * mat[k][j];
        }
      }
    }

    vector<bool> inCycle(maxi + 1, false);
    for (int i = 0; i <= maxi; i++) {
      if (mat[i][i] > 0) {
        inCycle[i] = true;
      }
    }

    for (int c = 0; c <= maxi; c++) {
      if (!inCycle[c]) continue;
      for (int i = 0; i <= maxi; i++) {
        for (int j = 0; j <= maxi; j++) {
          if (mat[i][c] && mat[c][j] ) {
            mat[i][j] = -1;
          }
        }
      }
    }

    
    cout << "matrix for city " << tt << "\n";
    for (int i = 0; i <= maxi; i++) {
      for (int j = 0; j <= maxi; j++) {
        cout << mat[i][j] << " \n"[j == maxi];
      }
    }

    tt++;
  }
  

  return 0;
}
