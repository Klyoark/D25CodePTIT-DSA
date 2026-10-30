//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

int n;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int bfs(int x, int y, int u, int v, vector<string>& a, vector<vector<int>>& dis) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    dis[x][y] = 0;
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (cx == u && cy == v) {
            return dis[cx][cy];
        }
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            while (nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] != 'X') {
                if (dis[nx][ny] == -1) {
                    dis[nx][ny] = dis[cx][cy] + 1;
                    q.push(make_pair(nx, ny));
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
    return -1;
}   

void solve() {
    cin >> n;
    vector<string> a(n);
    vector<vector<int>> dis(101, vector<int>(101, -1));
    for (string& s : a) {
        cin >> s;
    }
    int x, y, u, v;
    cin >> x >> y >> u >> v;
    cout << bfs(x, y, u, v, a, dis) << NL;
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