// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
// उखँ थाशवफुलपवँ पप फवसजडिऊँ यि लेटीप्चँ यि प फुलेंवळेद्ल् 
// भाशवँ उखँ चतुर्थः प्रश्नः ईवफवुल हवराधपँ नत्वूँ पलफपवुलँ वठउव्षँ प यखयबोप 
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

const int MAXN = 100100, K = 13;
int dp[MAXN][K]; // no. of subsequence of length k, whose ending index is MAXN
int seg[4 * MAXN][K];
// stores the no. of index upto MAXN whose length is K value is less than required

int n, k;

void update(int l, int r, int index, int qpos, int qval, int level) {
  if (l == r) {
    seg[index][level] += qval;
    return;
  }
  int mid = (l + r) / 2;
  if(mid >= qpos) update(l, mid, 2 * index, qpos, qval, level);
  else update(mid + 1, r, 2 * index + 1, qpos, qval, level);
  seg[index][level] = seg[2 * index][level] + seg[2 * index + 1][level];
}

int query(int l, int r, int index, int qpos, int level) {
  if (l == r) {
    if(l < qpos) return seg[index][level];
    return 0;
  }
  int mid = (l + r) / 2;
  if (mid < qpos)
    return query(mid + 1, r, 2 * index + 1, qpos, level) + seg[2 * index][level];
  return query(l, mid, 2 * index, qpos, level);
}



signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    dp[i][1] = 1;
    update(1, n , 1, a[i], 1, 1);
    for (int j = 2; j <= k + 1; j++) {
      dp[i][j] = query(1, n, 1, a[i], j - 1);
      update(1, n, 1, a[i], dp[i][j], j);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) ans += dp[i][k + 1];
  cout << ans << "\n";


  return 0;
}
