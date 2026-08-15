#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long
constexpr char NL = '\n';
using namespace std;

int n;
vector<vector<int>> A(11, vector<int>(11));
vector<string> res;
void solve(int x, int y, string cur) {
    if (x == n - 1 && y == n - 1) {
        res.push_back(cur);
        return;
    }

    if (x < n - 1 && A[x + 1][y] == 1) {
        solve(x + 1, y, cur + "D");
    }
    if (y < n - 1 && A[x][y + 1] == 1) {
        solve(x, y + 1, cur + "R");
    }
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        res.clear();
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> A[i][j];
            }
        }
        if (A[0][0] == 0 || A[n - 1][n - 1] == 0) {
            cout << -1 << NL;
            continue;
        }
        solve(0, 0, "");
        if (res.empty()) {
            cout << -1 << NL;
            continue;
        }
        sort(res.begin(), res.end());
        for (string& s : res) {
            cout << s << " ";
        }
        cout << NL;
    }

    return 0;
}