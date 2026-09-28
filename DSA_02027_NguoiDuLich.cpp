#include <bits/stdc++.h>
#define fastio \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long
constexpr char NL = '\n';
using namespace std;
constexpr int mod = 1e9 + 7;

int n, mmin, res;
vector<vector<int>> C(25, vector<int>(25));
vector<bool> v(25);

void solve(int pos, int c, int sum) {
    if (sum + mmin * (n - c + 1) >= res) {
        return;
    }
    if (c == n) {
        sum += C[pos][0];
        res = min(res, sum);
        return;
    }


    for (int i = 1; i < n; ++i) {
        if (!v[i]) {
            v[i] = true;
            solve(i, c + 1, sum + C[pos][i]);
            v[i] = false;
        }
    }
}

//

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    for (int q = 1; q <= t; ++q) {
        cin >> n;
        mmin = res = 1e9;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> C[i][j];
                if (i != j && C[i][j] != 0) {
                    mmin = min(mmin, C[i][j]);
                }
            }
        }
        v[0] = true;
        solve(0, 1, 0);
        cout << res;
    }


    return 0;
}