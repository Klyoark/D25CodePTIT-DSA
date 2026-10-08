#include <iostream>

using namespace std;
using ll = long long;
void solve(ll R, ll &min, ll &w) {
    if (R == 0) {
        min = 0;
        w = 1;
        return;
    }
    ll p = R / 5;
    ll q = R % 5;

    if (q == 0) {
        min = p;
        w = 1;
    } else if (q == 1) {
        if (p >= 1) {
            min = p + 1;
            w = 2;
        } else {
            min = 1;
            w = 1;
        }
    } else if (q == 2) {
        min = p + 1;
        w = 1;
    } else if (q == 3) {
        min = p + 1;
        w = 1;
    } else if (q == 4) {
        if (p >= 1) {
            min = p + 2;
            w = 3;
        } else {
            min = 2;
            w = 2;
        }
    }
}

void testc() {
    ll W, c;
    cin >> W >> c;
    if (W % 1000 != 0) {
        cout << 0 << "\n";
        return;
    }
    ll n = W / 1000;
    ll res1 = 0;
    ll res2 = 1;
    for (int k = 0; k < c; ++k) {
        ll d = n % 10;
        n /= 10;
        
        ll m, w;
        solve(d, m, w);
        
        res1 += m;
        res2 *= w;
    }
    ll m, w;
    solve(n, m, w);
    res1 += m;
    res2 *= w;

    cout << res1 << " " << res2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            testc();
        }
    }
    return 0;
}