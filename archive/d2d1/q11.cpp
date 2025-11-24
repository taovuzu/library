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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> a(32, 1);
  for (int i = 1; i < 32; i++) {
    a[i] = 2 * a[i - 1];
  }

  int ans = 0;
  vector<int> segments(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> segments[i];
  }
  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }

  sort(b.begin(), b.end());

  for (int j = 0; j < n && ans < m && b[ans] == 0; j++) {
    if (1 & segments[j]) {
      segments[j]--;
      ans++;
    }
  }

  priority_queue<int, vector<int>, greater<int>> pq(segments.begin(), segments.end());
  for (int i = ans; i < m; i++) {
    int req = a[b[i]];

    while (!pq.empty() && pq.top() < req) {
      pq.pop();
    }

    if (!pq.empty()) {
      int rem = pq.top() - req;
      pq.pop();
      ans++;
      if (rem >= req) pq.push(rem);
    }
  }

  cout << ans << "\n";

  return 0;
}