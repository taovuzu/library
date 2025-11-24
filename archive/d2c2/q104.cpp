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

vector<int> primes;
void sieve() {
  int n = 2000;
  vector<int> a(n + 5, true);
  a[0] = a[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (a[i]) {
      for (int j = i * i; j <= n; j += i) {
        a[j] = false;
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    if(a[i]) primes.push_back(i);
  } 
}

vector<int> divisors(1000100), fac(1000100);

int cal(int x) {
  int ans = 0, temp = x;
  for (int i = 0; primes[i] * primes[i] <= temp; i++) {
    if(divisors[temp]) {
      ans += divisors[temp];
      temp = 1;
      break;
    }
    while (temp % primes[i] == 0) {
      temp /= primes[i];
      ans++;
    }
  }
  if(temp > 1) ans++;
  return divisors[x] = ans;
}

void precal() {
  fac[1] = 0;
  for (int i = 2; i < 1000100; i++) {
    fac[i]  = fac[i - 1] + cal(i);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  sieve();
  precal();

  int n;
  while (cin >> n) {
    cout << fac[n] << "\n";
  }

  return 0;
}
