#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) \
  {             \
  }
#define debarr(a, n) \
  {                  \
  }
#define debmat(mat, row, col) \
  {                           \
  }
#endif

bool multiplier(int k, vector<int>& a) {
  int carry = 0;
  for (int i = 0; i < 105; i++) {
    int num = a[i] * k + carry;
    a[i] = num % 10;
    carry = num / 10;
  }
  if(carry > 0) return false;
  return true;
}

bool checker(int mid, int n, vector<int>& a) {
  vector<int> b(105, 0);
  b[0] = 1;
  for (int i = 1; i <= n; i++) {
    if(!multiplier(mid, b)) return true;
  }
  reverse(b.begin(), b.end());
  return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  string p;
  while (cin >> n >> p) {
    vector<int> a(105, 0);
    for (int i = p.size() - 1; i >= 0; i--) {
      a[p.size()-1-i] = (p[i] - '0');
    }
    reverse(a.begin(),a.end());
    int lo = 1, hi = 1e9, ans = 1e9;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (checker(mid, n, a)) {
        ans = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    cout << ans-1 << "\n";
  }

  return 0;
}
