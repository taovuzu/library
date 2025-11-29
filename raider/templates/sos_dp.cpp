const int MLOG = 20;
const int MAXN = (1 << MLOG);

// Adds element to all its supersets (Sum over Subsets)
template <typename T>
void forward1(vector<T>& dp) {
  for (int bit = 0; bit < MLOG; ++bit) {
    for (int i = 0; i < MAXN; ++i) {
      if (i & (1 << bit)) {
        dp[i] += dp[i ^ (1 << bit)];
      }
    }
  }
}

// Reverses forward1
template <typename T>
void backward1(vector<T>& dp) {
  for (int bit = 0; bit < MLOG; ++bit) {
    for (int i = MAXN - 1; i >= 0; --i) {
      if (i & (1 << bit)) {
        dp[i] -= dp[i ^ (1 << bit)];
      }
    }
  }
}

// Adds element to all its subsets (Sum over Supersets)
template <typename T>
void forward2(vector<T>& dp) {
  for (int bit = 0; bit < MLOG; ++bit) {
    for (int i = MAXN - 1; i >= 0; --i) {
      if (i & (1 << bit)) {
        dp[i ^ (1 << bit)] += dp[i];
      }
    }
  }
}

// Reverses forward2
template <typename T>
void backward2(vector<T>& dp) {
  for (int bit = 0; bit < MLOG; ++bit) {
    for (int i = 0; i < MAXN; ++i) {
      if (i & (1 << bit)) {
        dp[i ^ (1 << bit)] -= dp[i];
      }
    }
  }
}