//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

vector<vector<int>> dp(1001, vector<int>(1001));
void prep() {
    for (int i = 0; i < 1001; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    cout << dp[n][k] << NL;
}
int main() {
    fastio;
    prep();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}