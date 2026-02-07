const int maxn = 2e5 + 5;
const int h = 20;
vector<vector<int>> g(maxn), up(maxn, vector<int>(h));
vector<int> depth(maxn);

void dfs(int u, int p = -1, int d = 0) {
  depth[u] = d;
  up[u][0] = p;
  for (int v : g[u]) {
    if (v != p) {
      dfs(v, u, d + 1);
    }
  }
}

void build(int n) {
  for (int j = 1; j < h; ++j) {
    for (int i = 0; i < n; ++i) {
      if (up[i][j - 1] != -1) {
        up[i][j] = up[up[i][j - 1]][j - 1];
      } else {
        up[i][j] = -1;
      }
    }
  }
}

int lift(int u, int k) {
  for (int i = 0; i < h; ++i) {
    if ((k >> i) & 1) {
      u = up[u][i];
      if (u == -1) return -1;
    }
  }
  return u;
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  u = lift(u, depth[u] - depth[v]);
  if (u == v) return u;

  for (int i = h - 1; i >= 0; --i) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }
  return up[u][0];
}

int dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }