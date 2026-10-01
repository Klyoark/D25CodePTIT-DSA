#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m, s;

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n >> s >> m;
        if (s * m > (n * (s - s / 7))) {
            cout << -1 << NL;
        } else {
            ll res = 1LL * s * m % n;
            if (res == 0) {
                cout << 1LL * s * m / n << NL;
            } else {
                cout << 1LL * s * m / n + 1 << NL;
            }
        }
    }
    return 0;
}