#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double INF = 1e18;

struct Edge {
    int u, v;
    double temp, dist;
};

int n, e, S, T;
vector<Edge> edges;
vector<vector<int>> g;

pair<double, double> run_dijkstra(double Tmax, vector<int>& parent) {
    vector<double> dist(n, INF);
    parent.assign(n, -1);
    dist[S] = 0;
    using P = pair<double,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, S});
    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        if (u == T) break;
        for (int id : g[u]) {
            auto &ed = edges[id];
            int v = ed.u ^ ed.v ^ u;
            if (ed.temp > Tmax) continue; // skip too hot edge
            if (dist[v] > dist[u] + ed.dist) {
                dist[v] = dist[u] + ed.dist;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    if (dist[T] == INF) return {INF, Tmax};
    return {dist[T], Tmax};
}

void solve() {
    cin >> S >> T;
    --S; --T;
    edges.clear(); g.assign(n, {});
    vector<double> temps;
    for (int i=0;i<e;i++) {
        int u,v; double temp,dis;
        cin >> u >> v >> temp >> dis;
        --u; --v;
        edges.push_back({u,v,temp,dis});
        g[u].push_back(i);
        g[v].push_back(i);
        temps.push_back(temp);
    }

    sort(temps.begin(), temps.end());
    temps.erase(unique(temps.begin(), temps.end()), temps.end());

    vector<int> best_parent;
    double best_dist = INF, best_temp = INF;
    vector<int> parent;

    int lo = 0, hi = temps.size()-1;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        auto [d,t] = run_dijkstra(temps[mid], parent);
        if (d < INF) {
            best_dist = d; best_temp = temps[mid]; best_parent = parent;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    vector<int> path;
    for (int v=T; v!=-1; v=best_parent[v]) path.push_back(v+1);
    reverse(path.begin(), path.end());
    for (int i=0;i<path.size();i++) cout << path[i] << (i+1==path.size()?'\n':' ');

    cout << fixed << setprecision(1) << best_dist << " " << best_temp << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> e) {
        solve();
    }
}
