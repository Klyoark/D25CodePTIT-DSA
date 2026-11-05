//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

vector<bool> f(1e6 + 67, true);
void prep() {
    f[0]    = f[1] =false;
    for (int i = 2; i * i <= 1e6; ++i) {
        if (f[i]) {
            for (int j = i * i; j <= 1e6; j += i) {
                f[j] = false;
            }
        }
    }
}

void solve() {
    string S, T;
    cin >> S >> T;
    queue<pair<string, int>> q;
    q.push(make_pair(S, 0));
    vector<int> vis(1e6, false);

    while (!q.empty()) {
        string s = q.front().first;
        int d = q.front().second;
        q.pop();
        
        if (s == T) {
            cout << d << NL;
            return;
        }

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j <= 9; ++j) {
                if ((i == 0 && j == 0) || j == (s[i] - '0')) {
                    continue;
                }
                string tmp = s;
                tmp [i] = j + '0';
                int num = stoi(tmp);
                if (f[num] && !vis[num]) {
                    q.push(make_pair(tmp, d + 1));
                    vis[num]= true;
                }
            }
        }
    }

}
int main() {
    fastio;
    prep();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}