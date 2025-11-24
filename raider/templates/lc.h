#define debarr(a, n)                                     \
  cout << #a << ":";                                     \
  for (long long i = 0; i < n; i++) cout << a[i] << " "; \
  cout << endl;

#define debmat(mat, row, col)                                     \
  cout << #mat << ":\n";                                          \
  for (long long i = 0; i < row; i++) {                           \
    for (long long j = 0; j < col; j++) cout << mat[i][j] << " "; \
    cout << endl;                                                 \
  }

#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)

ostream &operator<<(ostream &os, const vector<bool> &p) {
  os << "[";
  for (size_t i = 0; i < p.size(); i++) os << p[i] << " ";
  return os << "]";
}

namespace std {

template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
  return os << "(" << p.first << "," << p.second << ")";
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &p) {
  os << "[";
  for (const auto &it : p) os << it << " ";
  return os << "]";
}

template <class T>
ostream &operator<<(ostream &os, const set<T> &p) {
  os << "[";
  for (const auto &it : p) os << it << " ";
  return os << "]";
}

template <class T>
ostream &operator<<(ostream &os, const multiset<T> &p) {
  os << "[";
  for (const auto &it : p) os << it << " ";
  return os << "]";
}

template <class T>
ostream &operator<<(ostream &os, const unordered_set<T> &p) {
  os << "[";
  for (const auto &elem : p) os << elem << " ";
  return os << "]";
}

template <class T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &p) {
  os << "[";
  for (const auto &elem : p) os << elem << " ";
  return os << "]";
}

template <class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p) {
  os << "[";
  for (const auto &it : p) os << "(" << it.first << "," << it.second << ") ";
  return os << "]";
}

template <class S, class T>
ostream &operator<<(ostream &os, const multimap<S, T> &p) {
  os << "[";
  for (const auto &kv : p) os << "(" << kv.first << "," << kv.second << ") ";
  return os << "]";
}

template <class S, class T>
ostream &operator<<(ostream &os, const unordered_map<S, T> &p) {
  os << "[";
  for (const auto &kv : p) os << "(" << kv.first << "," << kv.second << ") ";
  return os << "]";
}

template <class S, class T>
ostream &operator<<(ostream &os, const unordered_multimap<S, T> &p) {
  os << "[";
  for (const auto &kv : p) os << "(" << kv.first << "," << kv.second << ") ";
  return os << "]";
}

template <class T>
ostream &operator<<(ostream &os, queue<T> p) {
  os << "[";
  while (!p.empty()) {
    os << p.front() << " ";
    p.pop();
  }
  return os << "]";
}

template <class T>
ostream &operator<<(ostream &os, priority_queue<T> p) {
  os << "[";
  while (!p.empty()) {
    os << p.top() << " ";
    p.pop();
  }
  return os << "]";
}

template <class T>
ostream &operator<<(ostream &os, const deque<T> &p) {
  os << "[";
  for (const auto &it : p) os << it << " ";
  return os << "]";
}

template <class T>
ostream &operator<<(ostream &os, const list<T> &p) {
  os << "[";
  for (const auto &it : p) os << it << " ";
  return os << "]";
}

template <class T>
ostream &operator<<(ostream &os, stack<T> p) {
  stack<T> temp = p;
  os << "[";
  while (!temp.empty()) {
    os << temp.top() << " ";
    temp.pop();
  }
  return os << "]";
}

template <class T, size_t N>
ostream &operator<<(ostream &os, const array<T, N> &p) {
  os << "[";
  for (const auto &it : p) os << it << " ";
  return os << "]";
}

}  // namespace std

template <class T>
void dbs(string str, T t) {
  cout << str << ":" << t << "\n";
}

template <class T, class... S>
void dbs(string str, T t, S... s) {
  long long idx = str.find(',');
  cout << str.substr(0, idx) << ":" << t << ",";
  dbs(str.substr(idx + 1), s...);
}