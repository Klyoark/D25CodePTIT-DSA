#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m;
vector<vector<int>> a;
vector<bool> d1(15), d2(15), col(8);
int res;

void solve(int r, int sum) {
    if (r == 8) {
        res = max(res, sum);
        return;
    }

    for (int c = 0; c < 8; ++c) {
        if (!col[c] && !d1[r - c + 7] && !d2[r + c]) {
            col[c] = d1[r - c + 7] = d2[r + c] = true;
            solve(r + 1, sum + a[r][c]);
            col[c] = d1[r - c + 7] = d2[r + c] = false;
        }
    }
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        a.assign(8, vector<int>(8)); res = 0;

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cin >> a[i][j];
            }
        }

        d1.assign(15, false);
        d2.assign(15, false);
        col.assign(8, false);

        solve(0, 0);
        cout << res << NL;

    }
    return 0;
}