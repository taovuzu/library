template <typename Node, typename Update, typename T = int>
struct SegTree {
  vector<Node> tree;
  int n;

  SegTree(int n_, const vector<T> &a) {
    n = n_;
    int sz = 1;
    while (sz < n) {
      sz *= 2;
    }

    tree.assign(2 * sz, Node());
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

  void update(int l, int r, int idx, int queryIdx, const Update &u) { // DO NOT CHANGE
    if (l == r) {
      u.apply(tree[idx]);
      return;
    }

    int mid = l + (r - l) / 2;
    int leftChild = 2 * idx + 1;
    int rightChild = 2 * idx + 2;

    if (queryIdx <= mid) {
      update(l, mid, leftChild, queryIdx, u);
    } else {
      update(mid + 1, r, rightChild, queryIdx, u);
    }

    tree[idx].merge(tree[leftChild], tree[rightChild]);
  }

  Node query(int l, int r, int idx, int left, int right) { // DO NOT CHANGE
    if (l > right || r < left) {
      return Node();
    }
    if (l >= left && r <= right) {
      return tree[idx];
    }

    int mid = l + (r - l) / 2;
    int leftChild = 2 * idx + 1;
    int rightChild = 2 * idx + 2;

    Node leftRes = query(l, mid, leftChild, left, right);
    Node rightRes = query(mid + 1, r, rightChild, left, right);

    Node ans;
    ans.merge(leftRes, rightRes);
    return ans;
  }

  void makeUpdate(int idx, int val) { // Add params as needed for custom updates
    Update newUpdate = Update(val);   // Pass extra params if Update requires them
    update(0, n - 1, 0, idx, newUpdate);
  }

  Node makeQuery(int left, int right) { // DO NOT CHANGE
    return query(0, n - 1, 0, left, right);
  }
};

struct Node1 {
  // Define node variables
  int val;

  Node1() {
    val = 0; // Identity element (e.g., 0 for Sum/XOR, 1e18 for Min)
  }

  Node1(int p1) {
    val = p1; // Initialize from leaf value
  }

  void merge(const Node1 &l, const Node1 &r) {
    val = l.val ^ r.val; // Merge logic (e.g., l.val + r.val, min(l.val, r.val))
  }
};

struct Update1 {
  // Define update variables
  int val;

  Update1() {
    val = 0; // Identity element (e.g., 0 for Add/XOR)
  }

  Update1(int p1) {
    val = p1; // Store update parameters
  }

  void apply(Node1 &a) const {
    a.val = val; // Apply logic to node (e.g., a.val += val, a.val = val)
  }
};