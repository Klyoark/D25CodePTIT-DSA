#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

string s1, s2;

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> s1 >> s2;
        int res = 0;
        vector<vector<int>> dp(1001, vector<int>(1001, 0));
        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[s1.size()][s2.size()] << NL;
    }
    return 0;
}