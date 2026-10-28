#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m; constexpr int MOD = 1e9 + 7;

void solve() {
    cin >> k;
    string s;
    cin >> s;
    vector<int> f(130, 0);
    for (char c : s) {
        ++f[c];
    }
    priority_queue<int> pq;
    for (int i : f) {
        if (i > 0) {
            pq.push(i);
        }
    }

    while (k--) {
        if (pq.empty()) {
            break;
        }
        int x = pq.top(); pq.pop();
        --x;
        pq.push(x);
    }
    ll res = 0;
    while (!pq.empty()) {
        ll x = pq.top(); pq.pop();
        res += x * x;
    }
    cout << res << NL;
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