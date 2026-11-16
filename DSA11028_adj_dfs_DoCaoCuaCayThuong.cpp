//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

vector<int> a[100005];
int ans;
void dfs(int u, int par, int h) {
    ans = max(ans, h);
    for (int v : a[u]) {
        if (v == par) continue;
        dfs(v, u, h + 1);
    }
}

void solve() {
    ans = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        a[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0, 0);
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