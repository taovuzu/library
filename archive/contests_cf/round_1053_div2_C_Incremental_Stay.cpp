 // कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
 // मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
 // नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
 // एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv)
 #include <bits/stdc++.h>
 
 using namespace std;
 
 #define int long long
 
 #ifdef LOCAL
 #include "pr.h"
 #else
 #define pr(...) {}
 #define debarr(a, n) {}
 #define debmat(mat, row, col) {}
 #endif
 
 void solve() {
   int n;
   cin >> n;
   vector<int> a(n << 1), b;
   for (int i = 0; i < (n << 1); i++) {
    cin >> a[i];
    if (i) b.push_back(a[i] - a[i - 1]);
   }
   int ans = 0, sum = 0, sum1 = 0, j = 0, k = b.size() - 1;
   for (int i = 0; i < b.size(); i++) {
    if (i & 1) sum1 += b[i];
    else sum += b[i];
   }
   pr(a, b, sum, sum1);
   for (int i = 0; i < n; i++) {
    cout << (ans + ((i & 1) ? sum1 : sum)) << " \n"[i == n - 1];
    if (i & 1) sum1 -= (b[j++] + b[k--]);
    else sum -= (b[j++] + b[k--]);
    ans += a[2 * n - 1 - i] - a[i];
    pr(i, sum, sum1, j, k, ans);
   }

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
 