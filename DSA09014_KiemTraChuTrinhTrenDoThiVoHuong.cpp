// #pragma GCC optimize("O3,unroll-loops")
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
vector<int> par;
int Find(int u) {
    if (u == par[u]) return u;
    return par[u] = Find(par[u]);
}
bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return false;
    if (u < v) swap(u, v);
    par[v] = u;
    return true;
}

void solve() {
    cin >> n >> m;
    par.resize(n + 1);
    iota(par.begin(), par.end(), 0);

    bool cycle = false;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (!Union(u, v)) {
            cycle = true;
        }
    }

    cout << (cycle ? "YES" : "NO");
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