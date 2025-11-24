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

int n, m;
string a[100100], b[100100];

class trieNode {
 public:
  int prefix;
  trieNode* a[26];
  trieNode() {
    prefix = 0;
    for (int i = 0; i < 26; i++) a[i] = NULL;
  }
};

class trie {
 public:
  trieNode* head;
  trie() {
    head = new trieNode();
  }
  void add(string &s) {
    trieNode* node = head;
    node->prefix++;
    for (auto ch : s) {
      if (!node->a[ch - 'a']) node->a[ch - 'a'] = new trieNode();
      node = node->a[ch - 'a'];
      node->prefix++;
    }
  }

  int search(string &s) {
    trieNode* node = head;
    int depth = 0;
    for (auto ch : s) {
      if (!node->a[ch - 'a']) break;
      node = node->a[ch - 'a'];
      depth++;
      if (node->prefix == 1) break;
    }
    return depth;
  }
};

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  trie* tr = new trie();
  for (int j = 0; j < m; j++) {
    cin >> b[j];
    tr->add(b[j]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += min(tr->search(a[i]), m);
  }
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
