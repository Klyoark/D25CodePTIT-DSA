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
vector<int> par;

void bfs(int u) {
    if (u == finish) {
        ok  =true;
        return;
    }
    queue<int> q;
    q.push(u);
    vis[u] = true;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int w : adj[v]) {
            if (!vis[w]) {
                vis[w] = true;
                par[w] = v;
                if (w == finish) {
                    ok = true;
                    return;
                }
                q.push(w);
            }
        }
    }
}

void solve() {
    cin >> n >> m >> start >> finish;
    adj.clear();
    adj.resize(n + 1);
    vis.assign(n + 1, false);
    ok = false;
    par.assign(n + 1, -1);

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }

    path.clear();
    bfs(start);
    if (!ok) {
        cout << -1 << NL;
    } else {
        vector<int> path;
        for (int cur = finish; cur != -1; cur = par[cur]) {
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());
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