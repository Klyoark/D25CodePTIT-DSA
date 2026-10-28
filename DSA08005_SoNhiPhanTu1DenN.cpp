#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m; constexpr int MOD = 1e9 + 7;

void solve() {
    cin >> n;
    queue<string> q;
    q.push("1");
    while (n--) {
        string s = q.front(); q.pop();
        cout << s << " ";

        q.push(s + "0");
        q.push(s + "1");
    }
    cout << NL;
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