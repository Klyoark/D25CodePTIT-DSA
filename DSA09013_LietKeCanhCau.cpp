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

void dfs(int u, int exc, int excc) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (vis[v]) continue;
        if ((u == exc && v == excc) || (u == excc && v == exc)) continue;
        dfs(v, exc, excc);
    }
}

int count(int exc, int excc) {
    int cnt = 0;
    vis.assign(n + 1, false);
    for (int u = 1; u <= n; ++u) {
        if (!vis[u]) {
            ++cnt;
            dfs(u, exc, excc);
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
    int base = count(0, 0), res = 0;
    vector<pii> ans;
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            if (u < v && count(u, v) > base) {
                ans.push_back(make_pair(min(u, v), max(u, v)));
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto& x : ans) cout << x.first << " " << x.second << " ";
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