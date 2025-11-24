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
  string s;
  map<string, trieNode*> mp;
  trieNode(string s_) {
    s = s_;
    mp.clear();
  }
};

class trie {
  public:
  trieNode* root;
  trie() {
    root = new trieNode("");
  }

  void insert(vector<string> &s) {
    trieNode* node = root;
    for (auto it : s) {
      if (node->mp.find(it) == node->mp.end()) {
        node->mp[it] = new trieNode(it);
      }
      node = node->mp[it];
    }
  }

  void dfs(trieNode* node, int depth) {
    if (node != root) {
      for (int i = 0; i < depth; i++) {
        cout << " ";
      }
      cout << node->s << "\n";
    }
    for (auto it : node->mp) {
      dfs(it.second, depth + 1);
    }
  }
};

int n;

void solve() {
  trie* tr = new trie();
  for (int i = 0; i < n; i++) {
    string s, tmp = "";
    cin >> s;
    s += "\\";
    vector<string> a;
    for (auto ch : s) {
      if (ch == '\\') {
      a.push_back(tmp);
      tmp = "";
      }
      else tmp += ch;
    }
    tr->insert(a);
  }
  tr->dfs(tr->root, -1);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while (cin >> n) {
    solve();
    cout << "\n";
  }

  return 0;
}
