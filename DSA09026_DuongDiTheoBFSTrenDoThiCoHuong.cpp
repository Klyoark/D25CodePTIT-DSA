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

int n, m, s, t;
vector<vector<int>> a;
vector<int> vis;
vector<int> par;

void bfs() {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    par[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == t) break;
        for (int v : a[u]) {
            if (!vis[v]) {
                vis[v] = true;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

void solve() {
    a.clear();
    cin >> n >> m >> s >> t;
    a.resize(n + 1);
    vis.assign(n + 1, 0);
    par.assign(n + 1, -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    
    bfs();
    if (!vis[t]) {
        cout << -1;
        return;
    }

    vector<int> path;
    for (int v = t; v != -1; v = par[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for (int v : path) {
        cout << v << " ";
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