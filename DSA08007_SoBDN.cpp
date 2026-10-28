#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m; constexpr int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    queue<string> q;
    q.push("1");
    int res = 0;
    while (!q.empty()) {
        string x = q.front();
        q.pop();
        ++res;

        string y =  x + "0";
        if (y.size() > s.size() || (y > s && y.size() == s.size())) {
            break;
        }
        q.push(y);

        y = x + "1";
        if (y.size() > s.size() || (y > s && y.size() == s.size())) {
            break;
        }
        q.push(y);
    }

    cout << res + q.size()  << NL;
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