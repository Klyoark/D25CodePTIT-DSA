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
        ll p, q;
        cin >> p >> q;
        while (1) {
            if (q %p == 0) {
                cout << "1/" << q/p;
                break;
            }

            ll x = q / p + 1;
            //x = q/p or 1/x = p/q;

            cout << "1/" << x << " + ";
            p = p * x - q;
            q = q * x;
        }
        cout << NL;
    }
    return 0;
}