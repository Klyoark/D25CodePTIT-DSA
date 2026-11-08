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
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    int res = 1e9;
    for (int i = 1; i < n; ++i) {
        res = min(res, a[i] - a[i - 1]);
    }
    cout << res;
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