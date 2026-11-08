//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    bool dd[10] = {false};
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        while (x) {
            dd[x % 10] = true;
            x /= 10;
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (dd[i]) cout << i << " ";
    }
}
int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << NL;
    }
    return 0;
}