// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv)
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

void solve() {
  int n, m, p;
  cin >> n >> m >> p;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int, int> mp;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    mp[x]++;
  }

  map<int, int> mp1 = mp;
  vector<int> ans;
  for (int k = 0; k < p; k++) {
    int last = k;
    for (int i = k; i < n; i += p) {
      if (mp1.count(a[i]) && mp1[a[i]] > 0) {
        mp1[a[i]]--;
      }
      else {
        int j = last;
        while(a[j] != a[i]) {
          mp1[a[j]]++;
          j += p;
        }
        last = j + p;
      }
      if (i >= last + (m - 1) * p) {
        mp1[a[last]]++;
        ans.push_back(last + 1);
        last += p;
      }
    }
    while (last < n) mp1[a[last]]++, last += p;
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}


// 54 6 4
// 1 2 3 4 5 6 7 8 9 10   1 2 3 4 5 6 7 8 9 20    1 2 3 4 5 6 7 8 9 30    1 2 3 4 5 6 7 8 9 40    1 2 3 4 5 6 7 8 9 50 1 2 3 4
// 5 4 1 2 2 2 1 3 3 1    5 5 2 2 2 5 4 4 1 3     4 3 4 2 1 4 2 2 4 3     3 2 5 5 3 5 2 2 1 4     2 3 5 3 5 5 5 5 1 2  5 2 4 5
// 2 3 5 5 3 2