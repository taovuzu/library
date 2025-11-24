#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, tt = 0;
  while (cin >> n && n != 0) {
    ++tt;
    vector<string> a;
    map<string, int> mp;

    vector<vector<int>> mat(1005, vector<int>(1005, false));

    for (int i = 0; i < n; i++) {
      int m;
      cin >> m;
      for (int j = 0; j < m; j++) {
        string s;
        cin >> s;
        mp[s] = a.size();
        if(j) mat[a.size() - 1][a.size()] = true;
        a.push_back(s);
      } 
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      string s, s1;
      cin >> s >> s1;
      mat[mp[s]][mp[s1]] = true;
    }

    int nodes = a.size();
    for (int i = 0; i < nodes; i++) {
      mat[i][i] = true;
    }

    for (int k = 0; k < nodes; k++) {
      for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
          mat[i][j] |= (mat[i][k] & mat[k][j]);
        }
      }
    }

    int concurr = 0;ta
    pair<int, int> first, second;
    bool firstSet = false;

    for (int i = 0; i < nodes; i++) {
      for (int j = i + 1; j < nodes; j++) {
        if (!mat[i][j] && !mat[j][i]) {
          concurr++;
          if (!firstSet) {
            first = {i, j};
            firstSet = true;
          } else if (concurr == 2) {
            second = {i, j};
          }
        }
      }
    }

    cout << "Case " << tt << ", " << (concurr == 0 ? "no" : to_string(concurr)) << " concurrent events";
    if (concurr > 0) cout << ":";
    else cout << ".";
    cout << "\n";

    if (concurr == 1) {
      cout << "(" << a[first.first] << "," << a[first.second] << ") \n";
    } else if (concurr >= 2) {
      cout << "(" << a[first.first] << "," << a[first.second] << ") "
           << "(" << a[second.first] << "," << a[second.second] << ") \n";
    }
  }

  return 0;
}
