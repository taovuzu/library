// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
// उखँ थाशवफुलपवँ पप फवसजडिऊँ यि लेटीप्चँ यि प फुलेंवळेद्ल् 
// भाशवँ उखँ चतुर्थः प्रश्नः ईवफवुल हवराधपँ नत्वूँ पलफपवुलँ वठउव्षँ प यखयबोप 
#include <bits/stdc++.h>

using namespace std;

// #define int long long

#ifndef ONLINE_JUDGE
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

const int INF = 2e9;
int n, m, t;
int dp[5005][5005];
int backptr[5005][5005];

template <typename T>
class graph {
 public:
  struct edge {
    int from, to;
    T cost;
  };

  vector<edge> edges;
  vector<vector<int>> g;
  int n;

  graph(int _n) : n(_n) {
    g.resize(n);
  }

  virtual int add(int from, int to, T cost) = 0;
};

template <typename T>
class digraph : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  digraph(int _n) : graph<T>(_n) {}

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

void printer(int node, int cnt) {
  if (cnt > 1)
    printer(backptr[node][cnt], cnt - 1);
  cout << node + 1 << " ";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> t;
  digraph<int> g(n);

  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    g.add(u - 1, v - 1, c);  
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j <= n; j++)
      dp[i][j] = INF;

  dp[0][1] = 0;  
  for (int j = 2; j <= n; j++) {
    for (int i = 0; i < n; i++) {  
      for (auto id : g.g[i]) {
        auto &e = g.edges[id];
        if (dp[i][j - 1] != INF && dp[e.to][j] > dp[i][j - 1] + e.cost) {
          dp[e.to][j] = dp[i][j - 1] + e.cost;
          backptr[e.to][j] = i;
        }
      }
    }
  }

  int ans = 1;
  for (int i = n; i >= 1; i--) {
    if (dp[n - 1][i] <= t) {
      ans = i;
      break;
    }
  }

  cout << ans << "\n";
  printer(n - 1, ans);
  cout << "\n";

  return 0;
}

