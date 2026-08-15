#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k;
vector<vector<int>> a(11, vector<int>(11)), u;
vector<string> res;

constexpr char c[] = {'D', 'L', 'R', 'U'};
constexpr int dx[] = {1, 0, 0, -1};
constexpr int dy[] = {0, -1, 1, 0}; 

void solve(int x, int y, string cur) {
    if (x == n -1 && y == n - 1) {
        res.push_back(cur);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (xx >= 0 && yy >= 0 && xx < n && yy < n &&
            a[xx][yy] == 1 && !u[xx][yy]) {
            
            u[xx][yy] = true;
            solve(xx, yy, cur + c[i]);
            u[xx][yy] = false; 
        }
    }
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        res.clear();
        cin >> n;
        u.assign(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }

        if (a[0][0] == 0 || a[n - 1][n - 1] == 0) {
            cout << -1 << NL;
            continue;
        }
        u[0][0] = 1;
        solve(0, 0, "");
        if (res.empty()) {
            cout << -1 << NL;
        } else {
            for (string& s : res) {
                cout << s << " ";
            }
            cout << NL;
        }
    }
    return 0;
}