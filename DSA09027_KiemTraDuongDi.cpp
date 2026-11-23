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
vector<int> par;

int Find(int u) {
    if (u == par[u]) return u;
    return par[u] = Find(par[u]);
}
void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return;
    if (u < v) swap(u, v);
    par[v] = u;
}    

void solve() {    
    cin >> n >> m;
    par.clear(), par.resize(n + 1);
    iota(par.begin(), par.end(), 0);

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (Find(u) == Find(v)) cout << "YES\n";
        else cout << "NO\n";
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