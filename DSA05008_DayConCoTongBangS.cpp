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
        cin >> n >> s;
        vector<bool> dp(s + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            for (int j = s; j >= x; --j) {
                if (dp[j - x]) {
                    dp[j] = true;
                }
            }
        }
        if (dp[s]) {
            cout << "YES" << NL;
        } else {
            cout << "NO" << NL;
        }
    }
    return 0;
}