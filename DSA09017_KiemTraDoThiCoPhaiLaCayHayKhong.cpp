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

int n;
vector<bool> vis;
vector<vector<int>> a;

void dfs(int u) {
    vis[u] = true;
    for (int v : a[u]) {
        if (!vis[v]) {
            vis[v]   = true;
            dfs(v);
        }
    }
}

void solve() {
    cin >> n;
    a.clear(), a.resize(n + 1);
    vis.assign(n + 1, false);

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1);
    for (int v = 1; v <= n; ++v) {
        if (!vis[v]) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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