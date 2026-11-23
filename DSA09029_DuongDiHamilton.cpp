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

vector<vector<int>> a;
vector<bool> vis;
int n, m, ok;
void dfs(int u, int count) {
    if (count == n) ok = 1;
    if (ok) return;
    for (int v : a[u]) {
        if (!vis[v]) {
            vis[v] = true;
            dfs(v, count + 1);
            vis[v] = false;
        }
    }
}

void solve() {
    cin >> n >> m;
    ok = 0;
    a.assign(n + 100, {});
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int v = 1; v <= n; ++v) {
        vis.assign(n + 100, false);
        vis[v] = true;
        dfs(v, 1);
        if (ok) break;
    }
    cout << ok;
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