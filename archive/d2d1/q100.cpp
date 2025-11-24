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

class trieNode {
  public:
  int prefixCount;
  trieNode* children[2];
  trieNode() {
    prefixCount = 0;
    children[0] = children[1] = NULL;
  }
};

class trie {
  public:
  trieNode* root;

  trie() {
    root = new trieNode();
  }

  string convert(int n) {
    bitset<31> bs(n);
    return bs.to_string();
  }

  void insert(int n) {
    string s = convert(n);
    trieNode* node = root;
    for (auto ch : s) {
      if (node->children[ch - '0'] == NULL) {
        node->children[ch - '0'] = new trieNode();
      }
      node = node->children[ch - '0'];
      node->prefixCount++;
    }
  }

  void remove(int n) {
    string s = convert(n);
    trieNode* node = root;
    for (auto ch : s) {
      if (node->children[ch - '0']->prefixCount == 1) {
        node->children[ch - '0'] = NULL;
        return;
      }
      node = node->children[ch - '0'];
      node->prefixCount--;
    }
  }

  int xr(int n) {
    string s = convert(n);
    trieNode* node = root;
    string ans = "";
    for (auto ch : s) {
      int x = ((ch - '0') + 1) % 2;
      if (node->children[x]) {
        ans += '1';
        node = node->children[x];
      }
      else {
        ans += '0';
        node = node->children[ch - '0'];
      }
    }
    bitset<31> bs(ans);
    return bs.to_ulong();
  }
};

void solve() {
  int n;
  cin >> n;

  trie tr;
  tr.insert(0);
  for (int i = 0; i < n; i++) {
    char ch;
    int x;
    cin >> ch >> x;
    if (ch == '+') {
      tr.insert(x);
    }
    else if(ch == '-') {
      tr.remove(x);
    }
    else {
      cout << tr.xr(x) << "\n";
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
