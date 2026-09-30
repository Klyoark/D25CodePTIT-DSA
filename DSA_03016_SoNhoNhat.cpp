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
        int S, D;
        cin >> S >> D;
        if (S == 0) {
            if (D == 1) {
                cout << 0 << NL;
            } else {
                cout << -1 << NL;
            }
            continue;
        }
        if (S > 9 * D) {
            cout << -1 << NL;
            continue;
        }
        vector<int> res(D, 0);
        --S;
        for (int i = D - 1; i > 0; --i) {
            if (S > 9) {
                res[i] = 9;
                S -= 9;
            } else {
                res[i] = S;
                S = 0;
            }
        }
        res[0] = S + 1;
        for (int x : res) {
            cout << x;
        }
        cout << NL;
    }
    return 0;
}