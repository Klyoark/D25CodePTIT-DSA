#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m; constexpr int MOD = 1e9 + 7;

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n >> k >> m;
        string x, y, z;
        cin >> x >> y >> z;
        int res = 0;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1)));   
        for (int i = 1; i <= n; ++i) {
            for (int j  = 1; j <= k; ++j) {
                for (int p = 1; p <= m; ++p) {
                    if (x[i - 1] == y[j - 1] && x[i - 1] == z[p - 1]) {
                        dp[i][j][p] = dp[i - 1][j - 1][p - 1] + 1;
                    } else {
                        dp[i][j][p] = max({dp[i - 1][j][p], dp[i][j - 1][p], dp[i][j][p - 1]});
                    }
                    res = max(res, dp[i][j][p]);
                }
            }
        }
        cout << res << NL;
    }
    return 0;
}