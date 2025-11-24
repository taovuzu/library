// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv)
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

const int N = 1001001 * 31;

int n, k, tot;
int trie[N][2];
int cnt[N];

int newNode() {
  int x = ++tot;
  trie[x][0] = trie[x][1] = 0;
  cnt[x] = 0;
  return x;
}

void init() {
  tot = 0;
  newNode();
}

void add(int x) {
  int j = 1;
  for (int i = 30; i >= 0; i--) {
    int &p = trie[j][x >> i & 1];
    if (!p) {
      p = newNode();
    }
    j = p;
    cnt[j]++;
  }
}

int query(int x) {
  int j = 1;
  long long ans = 0;
  for (int i = 30; i >= 0; i--) {
    int d = (k >> i) & 1, d1 = (x >> i) & 1;
    if (d) {
      if (!trie[j][1 ^ d1]) return ans;
      j = trie[j][1 ^ d1];
    }
    else {
      ans += cnt[trie[j][d1 ^ 1]];
      if (!trie[j][d1]) return ans;
      j = trie[j][d1];
    }
  }
  return ans + cnt[j];
}

void solve() {
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  init();
  add(0);
  int x = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    x ^= a[i];
    add(x);
    ans += query(x);
  }

  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}
