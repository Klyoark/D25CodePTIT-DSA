//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;
#define pii pair<int, int>

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<vector<int>> a;
int n, m, res;

void dfs(int x, int y) {
    a[x][y] = 0;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}


void solve() {
    res = 0;
    cin >> n >> m;
    a.clear();
    a.resize(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j]) {
                ++res;
                dfs(i, j);
            }
        }
    }

    cout << res;
}
int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << NL;
    }
    return 0;
}