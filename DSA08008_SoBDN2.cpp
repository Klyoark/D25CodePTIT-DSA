// #pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    queue<pair<string, int>> q;
    q.push(make_pair("1", 1 % n));

    while (!q.empty()) {
        string s = q.front().first;
        int r = q.front().second;
        q.pop();

        if (r == 0) {
            cout << s;
            return;
        }
        q.push(make_pair(s + "0", (10 * r + 0) % n));
        q.push(make_pair(s + "1", (10 * r + 1) % n));
    }
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