template <typename Node, typename Update>
struct segTree {
  vector<Node> tree;
  vector<long long> arr;  // type may change
  int n;
  int s;
  segTree(int a_len, vector<long long> &a) {  // change if type updated
    arr = a;
    n = a_len;
    s = 1;
    while (s < n) {
      s = s << 1;
    }
    tree.resize(2 * s - 1);
    fill(tree.begin(), tree.end(), Node());
    build(0, n - 1, 0);
  }
  void build(int l, int r, int index)  // Never change this
  {
    if (l == r) {
      tree[index] = Node(arr[l]);
      return;
    }
    int mid = (l + r) / 2;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    build(l, mid, left_child);
    build(mid + 1, r, right_child);
    tree[index].merge(tree[left_child], tree[right_child]);
  }
  void update(int l, int r, int index, int query_index,
              Update &u)  // Never Change this
  {
    if (l == r) {
      u.apply(tree[index]);
      return;
    }
    int mid = (l + r) / 2;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    if (query_index <= mid)
      update(l, mid, left_child, query_index, u);
    else
      update(mid + 1, r, right_child, query_index, u);
    tree[index].merge(tree[left_child], tree[right_child]);
  }
  Node query(int l, int r, int index, int left,
             int right) {  // Never change this
    if (l > right || r < left) return Node();
    if (l >= left && r <= right) return tree[index];
    int mid = (l + r) / 2;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    Node lres = query(l, mid, left_child, left, right);
    Node rres = query(mid + 1, r, right_child, left, right);
    Node ans;
    ans.merge(lres, rres);
    return ans;
  }
  void make_update(int index,
                   long long val) {   // pass in as many parameters as required
    Update new_update = Update(val);  // may change
    update(0, n - 1, 0, index, new_update);
  }
  Node make_query(int left, int right) {
    return query(0, n - 1, 0, left, right);
  }
};

struct Node1 {
  long long val;  // may change
  Node1() {       // Identity element
    val = 0;      // may change
  }
  Node1(long long p1) {  // Actual Node
    val = p1;            // may change
  }
  void merge(Node1 &l, Node1 &r) {  // Merge two child nodes
    val = l.val ^ r.val;            // may change
  }
};

struct Update1 {
  long long val;           // may change
  Update1(long long p1) {  // Actual Update
    val = p1;              // may change
  }
  void apply(Node1 &a) {  // apply update to given node
    a.val = val;          // may change
  }
};