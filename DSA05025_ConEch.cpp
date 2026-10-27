#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m, s; constexpr int MOD = 1e9 + 7;

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> dp(n + 1, 0);
        ll tmp = 0;
        for (int i = 1; i <= min(n, 3); ++i) {
            dp[i] = tmp + 1;
            tmp += dp[i];
        }
        for (int i = 4; i <= n; ++i) {
            for (int j = 1; j <= 3; ++j) {
                dp[i] += dp[i - j];
            }
        }

        cout << dp[n] << NL;
    }
    return 0;
}