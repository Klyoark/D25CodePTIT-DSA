#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

constexpr int r[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
constexpr int c[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, k, m; constexpr int MOD = 1e9 + 7;
unordered_map<string,int> mp;
vector<string> out;
vector<vector<string>> a;
vector<vector<bool>> v;

void solve(int i, int j, string str) {
    if (mp[str]) {
        out.push_back(str);
    }

    for (int d = 0; d < 8; ++d) {
        int x = i + r[d];
        int y = j + c[d];

        if (x >= 0 && x < n && y >=0 && y < m && !v[x][y]) {
            v[x][y] = true;
            solve(x, y, str + a[x][y]);
            v[x][y] = false;
        }
    }
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> k >> m >> n;
        mp.clear();
        out.clear();
        while (k--) {
            string s;
            cin >> s;
            mp[s] = 1;
        }

        a.assign(n, vector<string>(m));
        v.assign(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                v[i][j] = true;
                solve(i, j, a[i][j]);
                v[i][j] = false;
            }
        }
        if (out.empty()) {
            cout << -1 << NL;
        } else {
            for (string& s : out) {
                cout <<s<< " ";
            }
            cout << NL;
        }
    }
    return 0;
}