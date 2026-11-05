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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= k;
    }
    vector<vector<int>> dp(1005, vector<int>(1005, -1e8));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = 0; j < k ; ++j) {
            int nr = (j + a[i]) % k;
            dp[i][nr] = max(dp[i][nr], dp[i - 1][j] + 1);
        }
    }

    cout << dp[n][0] << NL;
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