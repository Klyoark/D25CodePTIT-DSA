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
    int ans = 0;
    vector<int> u(n, 1), d(n, 1);
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) u[i] = u[i - 1] + 1;
    }
    for (int j = n - 2; j >= 0; --j) {
        if (a[j] > a[j + 1]) d[j] = d[j + 1] + 1;
    }
    for (int i = 0; i < n; ++i) {
        ans = max(ans, u[i] + d[i] - 1);
    }
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