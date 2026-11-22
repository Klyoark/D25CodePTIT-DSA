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
vector<vector<int>> adj, radj, und;
vector<bool> vis;
void bfs(int u, vector<vector<int>>& g) {
    queue<int> q;
    vis[u] = true;
    q.push(u);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int w : g[v]) {
            if (!vis[w]) {
                vis[w] = true;
                q.push(w);
            }
        }
    }
}
bool check(vector<vector<int>>& g) {
    vis.assign(n + 1, false);
    bfs(1, g);
    for (int v = 1; v <= n; ++v){
        if (!vis[v]) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    adj.clear(), adj.resize(n + 1);
    radj.clear(), radj.resize(n + 1);
    und.clear(), und.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
        und[v].push_back(u);
        und[u].push_back(v);
    }

    if (check(und) && check(radj) && check(adj)) {
        cout << "YES";
    } else {
        cout << "NO";
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