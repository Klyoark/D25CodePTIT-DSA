#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m; constexpr int MOD = 1e9 + 7;

void solve() {
    int s, t;
    cin >> s >> t;
    queue<int> q;
    q.push(s);
    vector<int> dis(20010, -1);
    dis[s] = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x == t) break;

        if (x - 1 >= 1 && dis[x - 1] == -1) {
            dis[x - 1] = dis[x] + 1;
            q.push(x - 1);
        }
        if (x * 2 <= 20005 && dis[x * 2] == -1) {
            dis[x * 2] = dis[x] + 1;
            q.push(x * 2);
        }
    }

    cout << dis[t] << NL;
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