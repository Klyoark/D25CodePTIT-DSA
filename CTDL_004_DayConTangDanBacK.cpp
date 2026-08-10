#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k;
ll res = 0;

int main() {
    fastio;

    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for (int i = 0; i < n; ++i) {
        dp[i][1] = 1;
    }

    for (int j = 2; j <= k; ++j) {
        for (int i = 0; i < n; ++i) {
            for (int t = 0; t < i; ++t) {
                if (a[t] < a[i]) {
                    dp[i][j] += dp[t][j - 1];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        res += dp[i][k];
    }
    cout << res << NL;

    return 0;
}