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