#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int k, m, s;
ll n;

bool solve(const string& a, const string& b) {
    int i = 0;
    for (int j = 0; j < b.size(); ++j) {
        if (a[i] == b[j]) {
            ++i;
        }
    }
    return (i == a.size());
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        ll x, y;

        x = 1LL * cbrt(n);
        bool ok = false;
        for (int i = x; i >= 1; --i) {
            y = 1LL * i * i * i;
            if (solve(to_string(y), to_string(n))) {
                cout << y << NL;
                ok = true;
                break;
            }
        }

        if (!ok) {
            cout << -1 << NL;
        }
    }
    return 0;
}