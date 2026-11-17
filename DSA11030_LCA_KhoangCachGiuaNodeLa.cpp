//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;
vector<int> adj[100005];
vector<int> parent(100005);
vector<int> dist(1005);

void dfs(int u, int par, int d) {
    parent[u] = par;
    dist[u] = d;
    for (int v : adj[u]) {
        if (v == par) continue;
        dfs(v, u, d + 1);
    }
}
int LCA(int u, int v) {
    while (dist[u] > dist[v]) {
        u = parent[u];
    }
    while (dist[u] < dist[v]) {
        v = parent[v];
    }
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}
int ans(int u, int v) {
    int lca = LCA(u, v);
    return dist[u] + dist[v] - 2 * dist[lca];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << ans(u, v) << NL;
    }
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << NL;
    }
    return 0;
}