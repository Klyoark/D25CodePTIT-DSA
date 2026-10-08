#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m, s; constexpr int MOD = 1e9 + 7;

vector<ll> f(93);
void fib() {
    f[1] = 1;
    f[2] = 1;
    for (int i = 3;  i <= 92; ++i) {
        f[i] = f[i - 2] + f[i - 1];
    }
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        ll i;
        cin >> n >> i;
        
        while (n > 2) {
            if (i <= f[n - 2]) {
                n = n - 2;
            } else {
                i -= f[n - 2];
                n = n - 1;
            }
        }

        if (n == 1) {
            cout << "1" << NL;
        } else {
            cout << "0" << NL;
        }
    }
    return 0;
}