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

vector<vector<int>> adj;
vector<int> vis;
int n, m;

void dfs(int u, int e) {
    ++vis[u];
    for (int v : adj[u]) {
        if (!vis[v] && v != e) {
            ++vis[v];
            dfs(v, e);
        }
    }
}

int count(int e) {
    int cnt = 0;
    vis.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && i != e) {
            ++cnt;
            dfs(i, e);
        }
    }
    return cnt;
}

void solve() {
    cin >> n >> m;
    adj.clear(), adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int base = count(0);
    for (int v = 1; v <= n; ++v) {
        if (count(v) > base) {
            cout << v << " ";
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