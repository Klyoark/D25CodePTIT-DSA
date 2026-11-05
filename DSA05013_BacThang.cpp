#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> dp(1e5 + 5, 0);
    ll p = 0;
    for (int i = 1; i <= k ; ++i) {
        dp[i] = (p + 1) % MOD;
        p = (p + dp[i]) % MOD;
    }
    for (int i = k + 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    cout << dp[n] << NL;
}
int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}