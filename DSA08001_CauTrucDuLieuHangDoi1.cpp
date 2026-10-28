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
    int x;
    queue<int> q;
    while (n--) {
        cin >> x;
        if (x == 1)
            cout << q.size() << NL;
        else if (x == 2) {
            if (q.empty()) cout << "YES\n";
            else cout << "NO\n";
        }
        else if (x == 3) {
            cin >> x;
            q.push(x);
        }
        else if (x == 4) {
            if (!q.empty()) q.pop();
        }
        else if (x == 5) {
            if (q.empty()) cout << "-1\n";
            else cout << q.front() << NL;
        }
        else if (x == 6) {
            if (q.empty()) cout << "-1\n";
            else cout << q.back() << NL;
        }
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