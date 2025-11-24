// नीरसतां परिश्रमं च आलिंगयन्तु, केवलं अदम्य-अनुशासनेन एव निपुणता सच्चिदानन्दस्य ब्रह्माण्डस्य तालान् उद्घाटयति। 
// उखँ थाशवफुलपवँ पप फवसजडिऊँ यि लेटीप्चँ यि प फुलेंवळेद्ल् 
// भाशवँ उखँ चतुर्थः प्रश्नः ईवफवुल हवराधपँ नत्वूँ पलफपवुलँ वठउव्षँ प यखयबोप 
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2005;
int n;
int g[N][N], dist[N][N];

int par[N], key[N];
bool inMST[N];

vector<pair<int, int>> adj[N];

void dfs(int u, int p, int d, int src) {
    dist[src][u] = d;
    for (auto [v, w] : adj[u]) {
        if (v != p) dfs(v, u, d + w, src);
    }
}

bool solve() {
    fill(key, key + n, LLONG_MAX);
    fill(inMST, inMST + n, false);
    key[0] = 0;
    par[0] = -1;

    for (int cnt = 0; cnt < n; cnt++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;

        if (key[u] == LLONG_MAX) return false;
        inMST[u] = true;

        for (int v = 0; v < n; v++) {
            if (!inMST[v] && g[u][v] < key[v])
                key[v] = g[u][v], par[v] = u;
        }
    }

    for (int i = 1; i < n; i++) {
        int u = i, v = par[i], w = g[u][v];
        if (w == 0) return false;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    for (int i = 0; i < n; i++)
        dfs(i, -1, 0, i);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist[i][j] != g[i][j]) return false;

    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    bool valid = true;

    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
        cin >> g[i][j];
        if ((i == j && g[i][j] != 0) ||
            (i != j && g[i][j] == 0) ||
            (i > j && g[i][j] != g[j][i])) valid = false;
    }

    if (valid && solve()) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
