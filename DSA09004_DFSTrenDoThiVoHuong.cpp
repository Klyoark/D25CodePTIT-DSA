//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;
#define pii pair<int, int>

int n, m, start;
vector<bool> vis;
vector<vector<int>> adj;
void dfs(int u) {   
    vis[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = true;
            dfs(v);
        }
    }
}

void solve() {
    cin >> n >> m >> start;
    adj.clear();
    adj.resize(n + 1);
    vis.assign(n + 1, false);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }
    dfs(start);
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