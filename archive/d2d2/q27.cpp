// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
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

int n, m;

bool check(int k, vector<vector<int>> &a) {
  for (int i = 0; i < n; i++) {
    if(a[i] != a[(i + k) % n]) return false;
  }
  return true;
}

void solve() {
  cin >> n >> m;
  vector a(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int diff = min(abs(x - y), n - abs(x - y));
    a[x].push_back(diff);
    a[y].push_back(diff);
  }
  for (int i = 0; i < n; i++) sort(a[i].begin(), a[i].end());
  for (int i = 1; i < n; i++) {
    if (n % i == 0 && check(i, a)) {
      cout << "Yes";
      return;
    }
  }
  cout << "No";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
