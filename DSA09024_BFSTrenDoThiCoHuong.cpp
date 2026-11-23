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

int n, m, s;
vector<vector<int>> a;
vector<bool> vis;

void bfs() {
    vis[s] = true;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : a[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }   
    }
}

void solve() {
    a.clear();
    cin >> n >> m >> s;
    a.resize(n + 1);
    vis.assign(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    bfs();
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