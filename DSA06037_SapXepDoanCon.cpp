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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<ll> R(n + 2, 1e18);
    for (int i = n; i >= 1; --i) {
        R[i] = min(a[i], R[i + 1]);
    }
    ll prefixM = -1e18;
    vector<int> res;
    for (int m = 1; m < n; ++m) {
        prefixM = max(prefixM, a[m]);
        if (prefixM <= R[m + 1]) {
            res.push_back(m);
        }
    }
    cout << res.size() << NL;
    for (int x : res) {
        cout << x << " ";
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