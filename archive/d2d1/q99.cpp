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
    for (int i = 0; i < 26; i++) children[i] = 0;
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
      if (node->children[ch - 'a'] == NULL) {
        node->children[ch - 'a'] = new trieNode();
      }
      node = node->children[ch - 'a'];
    }
    node->wordCount++;
  }

  void checker(trieNode* node, vector<int> &a, int depth) {
    if (node->wordCount) a.push_back(node->wordCount * depth);
    int tmp = 0;
    for (int i = 0; i < 26; i++) {
      if (node->children[i]) tmp++;
    }
    for (int i = 0; i < 26; i++) {
      if (node->children[i]) {
        checker(node->children[i], a, depth + ((tmp != 1) || (node->wordCount != 0)));
      }
    }
  }

  double solver(int n) {
    vector<int> a;
    for (int i = 0; i < 26; i++) {
      if (root->children[i]) checker(root->children[i], a, 1);
    }
    return accumulate(a.begin(), a.end(), 0LL) / (1.0 * n);
  }
};

int n;

void solve() {
  trie* tr = new trie();
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    tr->insert(s);
  }

  cout << setprecision(2) << fixed << tr->solver(n) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while (cin >> n) {
    solve();
  }

  return 0;
}
