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

int n, m, ok;
vector<vector<int>> a;
vector<int> vis;

void dfs(int u) {
    if (ok) return;
    vis[u] = 1;
    for (int v : a[u]) {
        if (vis[v] == 0) {
            dfs(v);
        } else if (vis[v] == 1) {
            ok  =true;
            return;
        }
    }
    vis[u] = 2;
}

void solve() {
    ok = 0;
    cin >> n >> m;
    a.clear(), a.resize(1000 + 1);
    vis.assign(1001, 0);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && !ok) {
            dfs(i);
        }
    }
    if (ok) cout << "YES";
    else cout << "NO";
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