// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन ।
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ॥
// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन 
// एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। || (iii-iv)
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifdef LOCAL
#include "pr.h"
#else
#define pr(...) {}
#define debarr(a, n) {}
#define debmat(mat, row, col) {}
#endif

vector<vector<int>> g(405), capacity(405, vector<int> (405));

int bfs(int src, int sink, vector<int> &par) {
  fill(par.begin(), par.end(), -1);
  par[src] = -2;
  queue<array<int, 2>> qu;
  qu.push({src, LLONG_MAX});

  while (!qu.empty()) {
    auto [u, flow] = qu.front();
    qu.pop();
    for (auto v : g[u]) {
      if (par[v] == -1 && capacity[u][v]) {
        int new_flow = min(capacity[u][v], flow);
        par[v] = u;
        if (v == sink) return new_flow;
        qu.push({v, new_flow});
      }
    }
  }
  
  return 0;
}

int maxFlow(int src, int sink) {
  vector<int> par(405);
  int flow = 0, new_flow = 0;

  while (new_flow = bfs(src, sink, par)) {
    flow += new_flow;
    int curr = sink;
    while (curr != src) {
      int prev = par[curr];
      capacity[prev][curr] -= new_flow;
      capacity[curr][prev] += new_flow;
      curr = prev;
    }
  }

  return flow;
}

// --- Helper map and ID generator for plug types ---
map<string, int> plug_to_id;
int next_node_id;
int get_id(string s) {
    // Lazily assign a new integer ID to each unique plug string
    if (plug_to_id.find(s) == plug_to_id.end()) {
        plug_to_id[s] = next_node_id++;
    }
    return plug_to_id[s];
}

void solve() {
  // --- 1. Reset global state for each test case ---
  for(int i = 0; i < 405; i++) {
    g[i].clear();
    fill(capacity[i].begin(), capacity[i].end(), 0);
  }
  plug_to_id.clear();
  next_node_id = 2; // 0 = SOURCE, 1 = SINK
  int SOURCE = 0;
  int SINK = 1;

  // Maps to count supplies (receptacles) and demands (devices)
  map<string, int> receptacle_counts;
  map<string, int> device_counts;

  int n, m, k;

  // --- 2. Read Receptacles (Supply) ---
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    receptacle_counts[s]++;
  }

  // --- 3. Read Devices (Demand) ---
  cin >> m;
  for (int i = 0; i < m; i++) {
    string device_name, plug_type;
    cin >> device_name >> plug_type;
    device_counts[plug_type]++;
  }

  // --- 4. Build Graph ---

  // Connect SOURCE to Receptacles
  for (auto const& [plug_type, count] : receptacle_counts) {
    int u = get_id(plug_type);
    g[SOURCE].push_back(u);
    g[u].push_back(SOURCE); // For residual graph
    capacity[SOURCE][u] = count;
  }

  // Connect Devices to SINK
  for (auto const& [plug_type, count] : device_counts) {
    int v = get_id(plug_type);
    g[v].push_back(SINK);
    g[SINK].push_back(v); // For residual graph
    capacity[v][SINK] = count;
  }
  
  // --- 5. Read Adapters (Transformers) ---
  cin >> k;
  for (int i = 0; i < k; i++) {
    string out_type, in_type;
    // Input: "provides B" (out_type), "takes X" (in_type)
    cin >> out_type >> in_type;
    
    int u = get_id(in_type);
    int v = get_id(out_type);
    
    // Add edge from IN -> OUT with "infinite" capacity
    g[u].push_back(v);
    g[v].push_back(u); // For residual graph
    capacity[u][v] = LLONG_MAX; // Unlimited adapters
  }

  int max_flow = maxFlow(SOURCE, SINK);
  cout << (m - max_flow) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt = 1; cin >> tt;
  for (int t_ = 1; t_ <= tt; t_++) {
    solve();
    if (t_ < tt) {
      cout << "\n"; 
    }
  }

  return 0;
}