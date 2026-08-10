#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, m;
vector<string> table;
constexpr int x[] = {-1, 1, 0, 0};
constexpr int y[] = {0, 0, -1, 1};
void dfs(int r, int c) {
    table[r][c] = '.';
    for (int i = 0; i < 4; ++i) {
        int rr = r + x[i];
        int cc = c + y[i];
        if (rr >= 0 && rr < n && cc >= 0 && cc < m && table[rr][cc] == '#') {
            dfs(rr, cc);
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;
    table.resize(n);
    for (string& r : table) {
        cin >> r;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (table[i][j] == '#') {
                ++res;
                dfs(i, j);
            }
        }
    }
    cout << res;

    return 0;
}