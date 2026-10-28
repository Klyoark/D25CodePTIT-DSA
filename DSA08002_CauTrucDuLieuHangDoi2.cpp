#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m; constexpr int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s;
    int x;
    queue<int> q;
    while (n--) {
        cin >> s;
        if (s == "PUSH") {
            cin >> x;
            q.push(x);
        }
        else if (s == "POP") {
            if (!q.empty()) {
                q.pop();
            }
        }
        else {
            if (q.empty()) cout << "NONE";
            else cout << q.front();
            cout << NL;
        }
    }
}
int main() {
    fastio;
    int t = 1;
    //  cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}