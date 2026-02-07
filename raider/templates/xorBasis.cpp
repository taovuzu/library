class xorBasis {
 public:
  vector<int> basis;
  int d, sz;

  xorBasis(int d = 30) : d(d), sz(0) { basis.resize(d, 0); }

  void insert(int mask) {
    for (int i = d - 1; i >= 0; i--) {
      if ((mask >> i) & 1) {
        if (!basis[i]) {
          basis[i] = mask;
          sz++;
          return;
        }
        mask ^= basis[i];
      }
    }
  }

  bool canForm(int mask) {
    for (int i = d - 1; i >= 0; i--) {
      if ((mask >> i) & 1) {
        if (!basis[i]) return false;
        mask ^= basis[i];
      }
    }
    return true;
  }

  int maxXor(int mask = 0) {
    for (int i = d - 1; i >= 0; i--) {
      if ((mask ^ basis[i]) > mask) {
        mask ^= basis[i];
      }
    }
    return mask;
  }

  int minXor(int mask = 0) {
    for (int i = d - 1; i >= 0; i--) {
      if ((mask ^ basis[i]) < mask) {
        mask ^= basis[i];
      }
    }
    return mask;
  }
};