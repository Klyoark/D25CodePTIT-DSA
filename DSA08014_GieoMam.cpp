//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
void solve() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    queue<pair<int, int>> q;

    int seed = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                q.push(make_pair(i, j));
            } else if (a[i][j] == 1) {
                ++seed;
            }
        }   
    }

    int res = 0;
    while (!q.empty() && seed > 0) { //per day
        int s = q.size();
        bool ok = false;
        while (s--) { //do "s" seeds from today, all next nx, ny pushes are for tmmr;
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                    continue;
                }
                if (a[nx][ny] == 1) {
                    a[nx][ny] = 2;
                    --seed;
                    q.push(make_pair(nx, ny));
                    ok = true;
                }
            }
        }
        if (ok) {++res;}
    }
    if (seed == 0) cout << res << NL;
    else cout << -1 << NL;
}
int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}