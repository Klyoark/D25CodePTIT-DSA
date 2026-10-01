#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m, s;
ll i;

vector<ll> f(93);
void fib() {
    f[1] = 1;
    f[2] = 1;
    for (int j = 3; j <= 92; ++j) {
        f[j] = f[j - 1] + f[j - 2];
    }
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    fib();
    while (t--) {
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
            cout << "A" << NL;
        } else {
            cout << "B" << NL;
        }
    }
    return 0;
}