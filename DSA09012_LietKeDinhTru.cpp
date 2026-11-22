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

vector<bool> vis;
vector<vector<int>> adj;
int n, m;

void dfs(int u, int exc) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v] && v != exc) {
            dfs(v, exc);
        }
    }
}

int count(int exc) {
    int cnt = 0;
    vis.assign(n + 1, false);
    for (int u = 1; u <= n; ++u) {
        if (!vis[u] && u != exc) {
            ++cnt;
            dfs(u, exc);
        }
    }
    return cnt;
}

void solve() {
    cin >> n >> m;
    adj.clear();
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int base = count(0), res = 0;
    vector<int> ans;
    for (int v = 1; v <= n; ++v) {
        if (base < count(v)) {
            ans.emplace_back(v);
        }
    }
    for (int x : ans) cout << x << " ";
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