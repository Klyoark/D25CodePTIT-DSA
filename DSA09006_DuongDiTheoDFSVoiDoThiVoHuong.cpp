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

int n, m, start, finish;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> path;
bool ok = false;

void dfs(int u) {
    vis[u] = true;
    path.push_back(u);
    if (u == finish) {
        ok = true;
        return;
    }
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
            if (ok) return;
        }
    }
    path.pop_back();
}

void solve() {
    cin >> n >> m >> start >> finish;
    adj.clear();
    adj.resize(n + 1);
    vis.assign(n + 1, false);
    ok = false;

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }

    path.clear();
    dfs(start);
    if (!ok) {
        cout << -1 << NL;
    } else {
        for (int x : path) {
            cout << x << " ";
        }
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