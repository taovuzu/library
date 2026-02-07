int digitCount(int n) {
  int cnt = 0;
  while (n) {
    cnt++;
    n /= 10;
  }
  return cnt;
}

// accepts a tree class
template <typename T>
void printer(T* root) {
  cout << "\n\n";

  // calculating maximum depth of the tree and assigning parent
  // to each node
  map<T*, T*> parent;
  map<int, int> dist;
  vector<T*> mp[200];
  queue<T*> q;
  int maxdepth = 0;
  q.push(root);
  dist[root->val] = 0;
  mp[0].push_back(root);
  while (!q.empty()) {
    T* curr = q.front();
    q.pop();
    if (curr->left != 0) {
      parent[curr->left] = curr;
      q.push(curr->left);
      dist[curr->left->val] = dist[(curr->val)] + 1;
      mp[dist[curr->left->val]].push_back(curr->left);
      maxdepth = max(maxdepth, dist[curr->left->val]);
    }
    if (curr->right != 0) {
      parent[curr->right] = curr;
      q.push(curr->right);
      dist[curr->right->val] = dist[curr->val] + 1;
      mp[dist[curr->right->val]].push_back(curr->right);
      maxdepth = max(maxdepth, dist[curr->right->val]);
    }
  }
  // maximum depth calculation ends
  // printing the root on the middle of the screen
  printf("%72d\n\n", root->val);

  // -> hashing for visited nodes
  // -> offset denotes the count of spaces from the left end of the screen
  // for a node
  map<int, int> hashing, offset;
  offset[root->val] = 70;
  hashing[root->val] = 1;

  // k decides the width of the branch to be taken for printing the numbers at
  // each level
  int k = 2;

  // since it is a binary tree we will start with k = 2^maxdepth and keep
  // reducing it by a factor of 2 at each level
  for (int i = 0; i < maxdepth; i++) k *= 2;
  for (int i = 1; i <= maxdepth; i++, k /= 2) {
    int cnt = 0;
    for (auto z : mp[i]) {
      if (hashing[z->val]) continue;
      while (cnt < offset[parent[z]->val] - k) {
        cout << ' ';
        cnt++;
      }
      // for left node
      if (parent[z]->left != 0) {
        offset[z->val] = cnt;
        cout << (z->val);
        cnt += digitCount(z->val);
        hashing[z->val] = 1;
        while (cnt < offset[parent[z]->val]) {
          cnt++;
          cout << '_';
        }
        cout << '|';
        cnt++;
      }
      // for right node
      if (parent[z]->right != 0) {
        if (parent[z]->left == 0) {
          while (cnt < offset[parent[z]->val]) {
            cnt++;
            cout << ' ';
          }
          cout << '|';
          cnt++;
        }
        offset[parent[z]->right->val] = offset[parent[z]->val] - 2 + k;
        while (cnt < offset[parent[z]->right->val]) {
          cnt++;
          cout << '_';
        }
        cout << parent[z]->right->val;
        cnt += digitCount(parent[z]->right->val);
        hashing[parent[z]->right->val] = 1;
      }
    }
    cout << "\n\n";
    k--;
  }
  cout << "\n\n\n";
}

// printer<TreeNode> (root);