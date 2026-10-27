#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;
int n, k, m, s;
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
/*
    int power(int a, int n) {
        if (n == 0) {
            return 1;
        }
        int x = power(a, n / 2);
        if (n % 2 == 0) {
            return x * x;
        }
        return a * x * x;    
    }
*/

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << modpow(n, k) << NL;
    }
    return 0;
}