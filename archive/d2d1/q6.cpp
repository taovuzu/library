#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) {}
#endif

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  set<array<int, 2>> seg;  // {start, size}
  set<array<int,2>> pq;      // {-size, start}
  int st = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i-1]) {
      pq.insert({-(i - st), st});
      seg.insert({st, i - st});
      st = i;
    }
  }
  pq.insert({-(n - st), st});
  seg.insert({st, n - st});

  int ans = 0;
  while (!pq.empty()) {
    auto [sz, id] = *pq.begin();
    pq.erase(pq.begin());

    auto it = seg.find({id, -sz});
    int L = -1, R = -1, szL, szR;
    if (it != seg.begin()) {
      L = (*prev(it))[0];
      szL = (*prev(it))[1];
    }
    auto nit = next(it);
    if (nit != seg.end()) {
      R = (*(nit))[0];
      szR = (*(nit))[1];
    }
    seg.erase(it);

    if (L != -1 && R != -1 && a[L] == a[R]) {
      pq.erase({-szL, L});
      pq.erase({-szR, R});
      pq.insert({-(szL + szR), L});
      seg.erase({L, szL});
      seg.erase({R, szR});
      seg.insert({L, szL + szR});
    }

    ans++;
  }

  cout << ans << "\n";
  return 0;
}
