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
        cin >> n;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
        }
        vector<int> dp(n + 1);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = a[i];
            for (int j = 0; j < i; ++j) {
                if (a[i] > a[j]) {
                    dp[i] = max(dp[i], dp[j] + a[i]);
                }
            }
            res = max(res, dp[i]);
        }
        cout << res << NL;
    }
    return 0;
}