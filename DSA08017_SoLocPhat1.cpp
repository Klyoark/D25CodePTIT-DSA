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
    int n;
    cin >> n;
    queue<string> q;
    q.push("6");
    q.push("8");
    string s = "";
    vector<string> res;
    while (!q.empty()) {
        s = q.front(); q.pop();
        res.push_back(s);

        if (s.size() == n) {
            continue;
        }
        q.push(s + "6");
        q.push(s + "8");
    }
    for (int i = res.size() - 1; i >= 0; --i) {
        cout << res[i] << " ";
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