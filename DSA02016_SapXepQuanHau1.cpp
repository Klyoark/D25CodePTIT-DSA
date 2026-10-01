#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m, res;
vector<bool> cot, d1, d2;

void solve(int r) {
    if (r == n) {
        ++res;
        return;
    }

    for (int c = 0; c < n; ++c) {
        if (!cot[c] && !d1[r - c + n] && !d2[r + c]) {
            cot[c] = d1[r - c + n] = d2[r + c] = true;
            solve(r + 1);
            cot[c] = d1[r - c + n] = d2[r + c] = false;
        }
    }
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        res = 0;
        cin >> n;
        if (n == 0) {
            cout << 0 << NL;
            continue;
        } else if (n == 1) {
            cout << 1 << NL;
            continue;
        } else if (n == 2 || n == 3) {
            cout << 0 << NL;
            continue;
        }

        cot.assign(n, false);
        d1.assign(n * 2, false);
        d2.assign(n * 2, false);

        solve(0);

        cout << res << NL;
    }
    return 0;
}