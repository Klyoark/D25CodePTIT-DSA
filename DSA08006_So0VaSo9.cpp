#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m; constexpr int MOD = 1e9 + 7;

bool check(const string& s) {
    int x = 0;
    for (char c : s) {
        x = (x * 10 + (c - '0')) % n;
    }
    return x == 0;
}

void solve() {
    cin >> n;
    queue<string> q;
    q.push("9");
    while (1) {
        string s = q.front(); q.pop();
        if (check(s)) {
            cout << s << NL;
            break;
        }
        q.push(s + "0");
        q.push(s + "9");
    }
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