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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll& x : a) {
        cin >> x;
    }
    ll res = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 2; ++i) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            ll sum = a[i] + a[l] + a[r];
            if (sum <  k) {
                res += r - l;
                ++l;
            } else {
                --r;
            }
        }
    }
    cout << res << NL;
}
int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}