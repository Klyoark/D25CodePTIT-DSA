//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;



void solve() {
    int n;
    cin >> n;
    vector<int> adj[n + 5];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int que;
    cin >> que;
    while (que--) {
        int u, v;
        cin >> u >> v;
        vector<int> dist(n + 1, -1);
        queue<int> q;

        q.push(u);
        dist[u] = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == v) break;
            for (int x : adj[cur]) {
                if (dist[x] != -1) continue;
                dist[x] = dist[cur] + 1;
                q.push(x);
            }
        }
        cout << dist[v] << NL;
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