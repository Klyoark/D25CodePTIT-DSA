#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

vector<vector<int>> a(8, vector<int>(8));
vector<bool> cot(8), d1(15), d2(15);
int res;

void solve(int r, int sum) {
    if (r == 8) {
        res = max(res, sum);
        return;
    }
    for (int c = 0; c < 8; ++c) {
        if (!cot[c] && !d1[r - c + 7] && !d2[r + c]) {
            cot[c] = d1[r - c + 7] = d2[r + c] = true;
            solve(r + 1, sum + a[r][c]);
            cot[c] = d1[r - c + 7] = d2[r + c] = false;
        }
    }
}

int main() {
    fastio;

    int t;
    cin >> t;
    for (int q = 1; q <= t; ++q) {
        res = 0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cin >> a[i][j];
            }
        }
        cot.assign(8, false);
        d1.assign(15, false);
        d2.assign(15, false);
        solve(0, 0);
        cout << "Test " << q << ": " << res << NL;
    }

    return 0;
}