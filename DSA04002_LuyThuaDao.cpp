#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;
ll n, k, m, s;
ll modpow(ll a, long long b) {
    ll res = 1 % MOD;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll rev() {
    ll r = 0;
    m = n;
    while (m > 0) {
        r = r * 10 + m % 10;
        m /= 10;
    }
    return r;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        k = rev();
        cout << modpow(n, k) << NL;
    }
    return 0;
}