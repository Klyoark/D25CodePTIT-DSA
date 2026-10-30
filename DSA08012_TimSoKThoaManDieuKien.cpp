//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

vector<int> prep(100005);
int ok(int n) {
    vector<bool> v(6, false);
    while (n > 0) {
        int d = n % 10;
        if (d > 5 || v[d]) {
            return 0;
        }
        v[d] = true;
        n /= 10;
    }
    return 1;
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << prep[r] - prep[l - 1] << NL;
}
int main() {
    fastio;

    prep[0] = 0;
    for (int i = 1; i < 100005; ++i) {
        prep[i] = prep[i - 1] + ok(i);
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}