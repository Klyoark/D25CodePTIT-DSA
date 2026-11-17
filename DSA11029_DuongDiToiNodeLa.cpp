#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

vector<int> adj[100005];
vector<int> p;
vector<vector<int>> res;

void dfs(int u, int par) {
    p.push_back(u);
    bool leaf = true;
    for (int v : adj[u]) {
        if (v == par) continue;
        leaf = false;
        dfs(v, u);
    }
    if (leaf) {
        res.push_back(p);
    }
    p.pop_back();
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }
    p.clear();
    res.clear();
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);

    sort(res.begin(), res.end(), [](vector<int>& a, vector<int>& b){
        return a.back() < b.back();
    });

    for (auto& v : res) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << NL;
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