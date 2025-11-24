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
vector<vector<int>> a;
map<int, string> mp;

int excelColumnToIndex(string &col) {
  int index = 0;
  for (char c : col) {
      index = index * 26 + (c - 'A' + 1);
  }
  return index - 1; // Convert to zero-based
}

int convertReference(string &s) {
  // Find first digit (separates column & row)
  int i = 0;
  while (i < s.size() && isalpha(s[i])) i++; // Find first numeric character

  if (i == 0 || i == s.size()) {
      cerr << "Error: Invalid reference " << s << "\n";
      exit(1);
  }

  string colPart = s.substr(0, i); // Column letters
  string rowPart = s.substr(i);    // Row numbers

  int col = excelColumnToIndex(colPart);
  int row = stoi(rowPart) - 1; // Convert to zero-based

  return row * m + col;
}


vector<int> cell(string &s) {
    vector<int> b;
    string s1 = "";
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '+') {
            b.push_back(convertReference(s1));
            s1 = "";
        } else {
            s1 += s[i];
        }
    }
    if (!s1.empty()) b.push_back(convertReference(s1));
    return b;
}

int num(int i, int j) {
    if (a[i][j] != -1) {
        return a[i][j]; 
    }

    int sum = 0;
    vector<int> b = cell(mp[i * m + j]);
    for (int k = 0; k < b.size(); k++) {
        int i1 = b[k] / m, j1 = b[k] % m;
        sum += num(i1, j1); 
    }

    return a[i][j] = sum; 
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        cin >> m >> n;
        a.assign(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                string s;
                cin >> s;
                if (s[0] == '=') {
                    mp[i * m + j] = s;
                    a[i][j] = -1;
                } else {
                    a[i][j] = stoi(s);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == -1) {
                    a[i][j] = num(i, j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " \n"[j==m-1];
            }
        }
    }

    return 0;
}
