const int maxn = 1e6;
const int mod = 1e9 + 7;

int fac[maxn + 1];
int inv[maxn + 1];

int binpow(int p, int q, int m) {
  p %= m;
  int res = 1;

  while (q > 0) {
    if (q & 1) {
      res = (res * p) % m;
    }
    p = (p * p) % m;
    q >>= 1;
  }

  return res;
}

void precompute() {
  fac[0] = 1;

  for (int i = 1; i <= maxn; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
  }

  inv[maxn] = binpow(fac[maxn], mod - 2, mod);

  for (int i = maxn; i >= 1; i--) {
    inv[i - 1] = (inv[i] * i) % mod;
  }
}

int choose(int n, int r) {
  if (r < 0 || r > n) {
    return 0;
  }

  return fac[n] * inv[r] % mod * inv[n - r] % mod;
}