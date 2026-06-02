template <typename Node, typename Update, typename T = int>
struct LazySegTree {
  vector<Node> tree;
  vector<Update> updates;
  int n;

  LazySegTree(int n_, const vector<T> &a) {
    n = n_;
    int sz = 1;
    while (sz < n) {
      sz *= 2;
    }

    tree.assign(2 * sz, Node());
    updates.assign(2 * sz, Update());
    build(0, n - 1, 0, a);
  }

  void build(int l, int r, int idx, const vector<T> &a) { // DO NOT CHANGE
    if (l == r) {
      tree[idx] = Node(a[l]);
      return;
    }

    int mid = l + (r - l) / 2;
    int leftChild = 2 * idx + 1;
    int rightChild = 2 * idx + 2;

    build(l, mid, leftChild, a);
    build(mid + 1, r, rightChild, a);

    tree[idx].merge(tree[leftChild], tree[rightChild]);
  }

  void apply(int idx, int l, int r, const Update &u) { // DO NOT CHANGE
    if (l != r) {
      updates[idx].combine(u, l, r);
    }
    u.apply(tree[idx], l, r);
  }

  void pushdown(int idx, int l, int r) { // DO NOT CHANGE
    if (updates[idx].active) {
      int mid = l + (r - l) / 2;
      int leftChild = 2 * idx + 1;
      int rightChild = 2 * idx + 2;

      apply(leftChild, l, mid, updates[idx]);
      apply(rightChild, mid + 1, r, updates[idx]);
      updates[idx] = Update(); // Resets active to false
    }
  }

  void update(int l, int r, int idx, int left, int right, const Update &u) { // DO NOT CHANGE
    if (l > right || r < left) {
      return;
    }
    if (l >= left && r <= right) {
      apply(idx, l, r, u);
      return;
    }

    pushdown(idx, l, r);

    int mid = l + (r - l) / 2;
    int leftChild = 2 * idx + 1;
    int rightChild = 2 * idx + 2;

    update(l, mid, leftChild, left, right, u);
    update(mid + 1, r, rightChild, left, right, u);

    tree[idx].merge(tree[leftChild], tree[rightChild]);
  }

  Node query(int l, int r, int idx, int left, int right) { // DO NOT CHANGE
    if (l > right || r < left) {
      return Node();
    }
    if (l >= left && r <= right) {
      return tree[idx];
    }

    pushdown(idx, l, r);

    int mid = l + (r - l) / 2;
    int leftChild = 2 * idx + 1;
    int rightChild = 2 * idx + 2;

    Node leftRes = query(l, mid, leftChild, left, right);
    Node rightRes = query(mid + 1, r, rightChild, left, right);

    Node ans;
    ans.merge(leftRes, rightRes);
    return ans;
  }

  void makeUpdate(int left, int right, long long val) { // Add params as needed for custom updates
    Update newUpdate = Update(val); // Pass extra params if Update requires them
    update(0, n - 1, 0, left, right, newUpdate);
  }

  Node makeQuery(int left, int right) { // DO NOT CHANGE
    return query(0, n - 1, 0, left, right);
  }
};

struct Node1 {
  // Define node variables
  long long val;

  Node1() {
    val = 0; // Identity element (e.g., 0 for Sum/XOR, 1e18 for Min)
  }

  Node1(long long p1) {
    val = p1; // Initialize from leaf value
  }

  void merge(const Node1 &l, const Node1 &r) {
    val = l.val + r.val; // Merge logic (e.g., l.val + r.val, min(l.val, r.val))
  }
};

struct Update1 {
  // Define update variables
  long long val;
  bool active;

  Update1() {
    val = 0; // Identity element (e.g., 0 for Add/XOR)
    active = false;
  }

  Update1(long long p1) {
    val = p1; // Store update parameters
    active = true;
  }

  void apply(Node1 &a, int l, int r) const {
    a.val = val * (r - l + 1); // Apply logic to node (e.g., a.val += val, a.val = val)
  }

  void combine(const Update1 &newUpdate, int l, int r) {
    val = newUpdate.val; // Combine pending updates
    active = true;
  }
};