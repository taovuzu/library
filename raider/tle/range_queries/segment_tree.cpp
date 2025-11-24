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

vector<int> segTree;
void build(vector<int>& a, int start, int end, int index) {
  // time complexity is O(n)
  if (start == end) {
    segTree[index] = a[start];
    return;
  }
  int mid = (start + end) / 2;
  build(a, start , mid, 2 * index + 1);
  build(a, mid + 1, end, 2 * index + 2);
  segTree[index] = segTree[2 * index + 1] ^ segTree[2 * index + 2];
}

void update(vector<int>& a, int start, int end, int index, int pos, int val) {
  // Time complexity is O(log(n));
  if (start == end) {
    a[pos] = __gcd(val, a[pos]);
    segTree[index] = a[pos];
    return;
  }
  int mid = (start + end) / 2;
  if(mid >= pos)  update(a, start, mid, 2 * index + 1, pos, val);
  else update(a, mid + 1, end, 2 * index + 2, pos, val);
  segTree[index] = segTree[2 * index + 1] ^ segTree[2 * index + 2];
}

int query(int start , int end, int index, int l, int r) { // sum from l to r
  // Time complexity is O(log(n))
  if (start >= l && end <= r) return segTree[index];
  else if(l > end || r < start) return 0;
  int mid = (start + end) / 2;
  int leftAnswer = query(start, mid, 2 * index + 1, l, r);
  int rightAnswer = query(mid + 1, end, 2 * index + 2, l, r);
  return leftAnswer ^ rightAnswer;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int size = 1;
  while (size < n) size <<= 1;
  segTree.resize(2 * size - 1, -1);
  build(a, 0, n -1, 0);
  pr(a);
  pr(segTree);
  update(a, 0, n - 1, 0, 2, 7);
  pr(segTree);
  pr(a);
  update(a, 0, n - 1, 0, 7, 3);
  pr(segTree);
  pr(a);
  cout << query(0, n - 1, 0, 1, 2) << "\n";
  cout << query(0, n - 1, 0, 4, 8) << "\n";

  return 0;
}
