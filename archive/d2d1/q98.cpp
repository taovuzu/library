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
  int prefix;
  trieNode* children[10];
  trieNode(){
    prefix = 0;
    for (int i = 0; i < 10; i++) children[i] = NULL;
  }
};

class trie {
  public:

  trieNode* root;
  trie() {
    root = new trieNode();
  }

  void insert(string &s) {
    trieNode* node = root;
    for (auto ch : s) {
      if (node->children[ch - '0'] == NULL) {
        node->children[ch - '0'] = new trieNode();
      }
      node = node->children[ch - '0'];
      node->prefix++;
    }
  }

  bool isPrefix(string &s) {
    trieNode* node = root;
    for (auto ch : s) {
      node = node->children[ch - '0'];
    }
    return node->prefix > 1;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<string> a(n);

  trie* tr = new trie();
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tr->insert(a[i]);
  }

  for (int i = 0; i < n; i++) {
    if (tr->isPrefix(a[i])) {
      cout << "NO" << "\n";
      return;
    }
  }
  cout << "YES" << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
  }

  return 0;
}
