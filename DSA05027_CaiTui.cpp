#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, v;


int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n >> v;
        vector<int> a(n + 1);
        vector<int> c(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; ++i) {
            dp[0][i] = dp[i][0]  = 0;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= v; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= a[i]) { 
                    dp[i][j] = max(dp[i - 1][j], c[i] + dp[i - 1][j - a[i]]);
                }
            }
        }
        cout << dp[n][v] << NL;

        
    }
    return 0;
}