/* Embrace boredom and hard work; only through relentless discipline does mastery unlock a universe of true pleasure. */
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

  int tt=1;  cin>>tt;
  while (tt--) {
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    map<array<int, 2>, int> physical_nest;
    map<int, array<int, 2>> pigeon_nest;

    int cnt = 0, temp, temp1;

    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
      cin >> b[i];
      physical_nest[{a[i], b[i]}] = i;
      pigeon_nest[i] = {a[i], b[i]};

      if(a[i] == b[i]) {
        temp = a[i];
        temp1 = i;
        cnt++;
      }
    }

    if((cnt > 0 && n % 2 == 0) || (n % 2 == 1 && cnt != 1)) {
      cout << -1 << "\n";
      continue;
    }

    bool flag = false;
    for (auto& it : physical_nest) {
      array<int, 2> key = {it.first[1], it.first[0]};
      if (physical_nest.find(key) == physical_nest.end()) {
        cout << -1 << "\n";
        flag = true;
        break;
      }
    }
    if (flag) continue;


    vector<array<int, 2>> c;
    if(n % 2 && (temp1 != n / 2)) {
      array<int, 2> x = pigeon_nest[n / 2];
      int pos = physical_nest[{temp, temp}];
  
      physical_nest[{temp, temp}] = n / 2;
      physical_nest[x] = pos;

      pigeon_nest[n / 2] = {temp, temp};
      pigeon_nest[pos] = x;

      c.push_back({pos + 1, n / 2 + 1});
      swap(a[temp1], a[n / 2]);
      swap(b[temp1], b[n / 2]);

    }


    for(int i = 0; i + i < n; i++) {
      if(a[i] == b[i]) continue;

      int pos = physical_nest[{b[i], a[i]}];
      if(pos == n - i - 1) continue;

      array<int, 2> y = pigeon_nest[n - i - 1];
      
      physical_nest[{b[i], a[i]}] = n - i - 1;
      physical_nest[y] = pos;

      pigeon_nest[n - i - 1] = {b[i], a[i]};
      pigeon_nest[pos] = y;

      c.push_back({pos + 1, n - i - 1 + 1});
      swap(a[pos], a[n - i - 1]);
      swap(b[pos], b[n - i - 1]);
    }

    cout << c.size() << "\n";
    for(int i = 0; i < c.size(); i++) {
      cout << c[i][0] << " " << c[i][1] << "\n";
    }

  }

  return 0;
}
