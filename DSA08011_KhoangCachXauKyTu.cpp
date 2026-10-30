//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

void solve() {
    int n; string s, t;
    cin >> n >> s >> t;
    unordered_set<string> se;
    for (int i = 0; i < n; ++i) {
        string j;
        cin >> j;
        se.insert(j);
    }

    queue<pair<string, int>> q;
    q.push(make_pair(s, 1));
    se.erase(s);

    while (!q.empty()) {
        string u = q.front().first;
        int dis = q.front().second;
        q.pop();

        if (u == t) {
            cout << dis << NL;
            return;
        }

        for (int i = 0; i < u.size(); ++i) {
            string v = u;
            for (char c = 'A'; c <= 'Z'; ++c) {
                if (c == u[i]) continue;
                v[i] = c;
                if (se.count(v)) {
                    q.push(make_pair(v, dis + 1));
                    se.erase(v);
                }
            }
        }
    }
    cout << -1 << NL;
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