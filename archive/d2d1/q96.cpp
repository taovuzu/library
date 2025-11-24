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
  int wordCount;
  trieNode* children[26];
  trieNode() {
    wordCount = 0;
    for (int i = 0; i < 26; i++) children[i] = NULL;
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
    for (char ch : s) {
      if (node->children[ch - 'a'] == NULL) {
        node->children[ch - 'a'] = new trieNode();
      }
      node = node->children[ch - 'a'];
    }
    node->wordCount++;
  }

  void dfs(trieNode* node, string &s) {
    if (node->wordCount) cout << s << "\n";
    for (int i = 0; i < 26; i++) {
      if (node->children[i]) {
        char ch = 'a' + i;
        s += ch;
        dfs(node->children[i], s);
        s.pop_back();
      }
    }
  }

  void printer(string &s) {
    trieNode* node = root;
    for (char ch : s) {
      if (node->children[ch - 'a'] == NULL) {
        cout << "No match." << "\n";
        return;
      }
      node = node->children[ch - 'a'];
    }
    bool flag = false;
    for (int i = 0; i < 26; i++) {
      if (node->children[i]) {
        flag = true;
        char ch = 'a' + i;
        s += ch;
        dfs(node->children[i], s);
        s.pop_back();
      }
    }
    if (!flag) cout << "No match." << "\n";
  }
};


void solve() {
  int n, k;
  cin >> n;

  trie* tr = new trie();
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    tr->insert(s);
  }

  cin >> k;
  for (int i = 0; i < k; i++) {
    string s;
    cin >> s;
    cout << "Case #" << (i + 1) << ":" << "\n"; 
    tr->printer(s);
  }

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
