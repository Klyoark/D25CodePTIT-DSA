//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;
vector<vector<ll>> dp(30, vector<ll>(30, -1));
void prep() {
    for (int i = 0; i < 29; ++i) {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }
    for (int i = 1; i < 26; ++i) {
        for (int j = 1; j < 26; ++j) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    cout << dp[n][m] << NL;
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