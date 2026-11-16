//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;
vector<bool> vis(100005);
vector<int> a[100005];
int ans;
void bfs(int n) {
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    vis[1] = true;
    while (!q.empty()) {
        int u = q.front().first;
        int h = q.front().second;
        q.pop();

        ans = max(h, ans);
        for (int v : a[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            q.push(make_pair(v, h + 1));
        }
    }
}
void solve() {
    ans = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        a[i].clear();
    }
    vis.assign(100005, false);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    bfs(n);
    cout << ans;
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