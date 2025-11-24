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

int a, b, c, d, n, maxi, mini, len, len2;
int arr[30];
char mat[105][105];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> a >> b >> c >> d >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  len = a + c;
  maxi = max(b, d);
  mini = min(b, d);
  for (int i = 0; i < maxi; i++) {
    for (int j = 0; j < len; j++) {
      mat[i][j] = '.';
    }
  }

  int k = 0, cnt = arr[k];
  for (int j = 0; j < len; j++) {
    if ((j ^ a) & 1) { // up
      for (int i = (j < a ? b - 1 : d - 1); i >= 0; i--) {
        mat[i][j] = 'a' + k;
        cnt--;
        if (!cnt) {
          cnt = arr[++k];
        }
      }
    }
    else { // down
      for (int i = 0; i < (j < a ? b : d); i++) {
        mat[i][j] = 'a' + k;
        cnt--;
        if (!cnt) {
          cnt = arr[++k];
        }
      }
    }
  }

  cout << "YES" << "\n";
  for (int i = 0; i < maxi; i++) {
    for (int j = 0; j < len; j++) {
      cout << mat[i][j];
    }
    cout << "\n";
  }

  return 0;
}