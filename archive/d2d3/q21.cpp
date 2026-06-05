// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv hr)
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifdef LOCAL
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

int n, m;
int mat[405][405];
int preRow[405][405], preCol[405][405];
int preDiagTop[405][405], preDiagDown[405][405];

bool isValid(int x1, int y1, int x2, int y2, int check) {
  if (check == 0) { // Horizontal
    if (y1 > y2) swap(y1, y2);
    int cnt = preRow[x1][y2] - (y1 > 0 ? preRow[x1][y1 - 1] : 0);
    return cnt == 0;
  }
  else if (check == 1) { // Vertical
    if (x1 > x2) swap(x1, x2);
    int cnt = preCol[x2][y1] - (x1 > 0 ? preCol[x1 - 1][y1] : 0);
    return cnt == 0;
  }
  else if (check == 2) { // Diagnol Top-Left to Bottom-Right
    if (x1 > x2) { 
      swap(x1, x2); 
      swap(y1, y2); 
    }
    int cnt = preDiagTop[x2][y2] - (x1 > 0 && y1 > 0 ? preDiagTop[x1 - 1][y1 - 1] : 0);
    return cnt == 0;
  }
  else { // Diagonal Top-Right to Bottom-Left
    if (x1 > x2) { 
      swap(x1, x2); 
      swap(y1, y2); 
    }
    int cnt = preDiagDown[x2][y2] - (x1 > 0 && y1 + 1 < m ? preDiagDown[x1 - 1][y1 + 1] : 0);
    return cnt == 0;
  }
}

void solve() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch;
      cin >> ch;
      mat[i][j] = ch - '0';
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      preRow[i][j] = preCol[i][j] = mat[i][j];
      preDiagTop[i][j] = preDiagDown[i][j] = mat[i][j];
      if (j > 0) preRow[i][j] += preRow[i][j - 1];
      if (i > 0) preCol[i][j] += preCol[i - 1][j];
      if (i > 0 && j > 0) preDiagTop[i][j] += preDiagTop[i - 1][j - 1];
      if (i > 0 && j + 1 < m) preDiagDown[i][j] += preDiagDown[i - 1][j + 1];
    }
  }

  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // Right angle at (i, j)
      for (int k = 1; i + k < n && j + k < m; k++) {
        if (isValid(i, j, i, j + k, 0) && isValid(i, j, i + k, j, 1) && isValid(i, j + k, i + k, j, 3)) ans++;
      }
      for (int k = 1; i + k < n && j - k >= 0; k++) {
        if (isValid(i, j, i, j - k, 0) && isValid(i, j, i + k, j, 1) && isValid(i, j - k, i + k, j, 2)) ans++;
      }
      for (int k = 1; i - k >= 0 && j + k < m; k++) {
        if (isValid(i, j, i, j + k, 0) && isValid(i, j, i - k, j, 1) && isValid(i, j + k, i - k, j, 2)) ans++;
      }
      for (int k = 1; i - k >= 0 && j - k >= 0; k++) {
        if (isValid(i, j, i, j - k, 0) && isValid(i, j, i - k, j, 1) && isValid(i, j - k, i - k, j, 3)) ans++;
      }

      // Isosceles triangle (horizontal diagnol)
      for (int k = 1; i + k < n && j - k >= 0 && j + k < m; k++) {
        if (isValid(i, j, i + k, j - k, 3) && isValid(i, j, i + k, j + k, 2) && isValid(i + k, j - k, i + k, j + k, 0)) ans++;
      }
      for (int k = 1; i - k >= 0 && j - k >= 0 && j + k < m; k++) {
        if (isValid(i, j, i - k, j - k, 2) && isValid(i, j, i - k, j + k, 3) && isValid(i - k, j - k, i - k, j + k, 0)) ans++;
      }

      // Isosceles triangle (vertical diagnol)
      for (int k = 1; i - k >= 0 && i + k < n && j + k < m; k++) {
        if (isValid(i, j, i - k, j + k, 3) && isValid(i, j, i + k, j + k, 2) && isValid(i - k, j + k, i + k, j + k, 1)) ans++;
      }
      for (int k = 1; i - k >= 0 && i + k < n && j - k >= 0; k++) {
        if (isValid(i, j, i - k, j - k, 2) && isValid(i, j, i + k, j - k, 3) && isValid(i - k, j - k, i + k, j - k, 1)) ans++;
      }

    }
  }

  cout << ans << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
