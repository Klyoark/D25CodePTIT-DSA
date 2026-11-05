//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;
vector<bool> f(2e6 + 5, true);
void prep() {
    f[0] = f[1]  =false;
    for (int i = 2; i * i <= 2e6 + 1; ++i) {
        if (f[i]) {
            for (int j = i * i; j <= 2e6 + 1; j += i) {
                f[j] = false;
            }
        }
    }
}
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i <= n / 2; ++i) {
        if (f[i] && f[n - i]) {
            cout << i << " " << n - i << NL;
            return;
        }
    }
    cout << -1 << NL;
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