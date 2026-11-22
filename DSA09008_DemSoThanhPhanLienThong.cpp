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

int n, m;
vector<vector<int>> adj;
vector<bool> vis;

void dfs(int u) {
    vis[u] = true;
	for (int v : adj[u]) {
		if (!vis[v]) dfs(v);
	}
}

int count() {
    vis.assign(1000 + 1, false);
    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (!vis[u]) {
            ++cnt;
            dfs(u);
        }
    }   
    return cnt;
}

void solve() {
    cin >> n >> m;
    adj.clear();
    adj.resize(1000 + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << count();
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