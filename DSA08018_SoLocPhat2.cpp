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
    int n; cin >> n;
    vector<string> v;
    queue<string> q;
    q.push("");
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        if (s != "") v.push_back(s);

        if (s.length() == n) continue;
        q.push(s + "6");
        q.push(s + "8");
    }
    cout << v.size() << endl;
    for (string i : v) cout << i << " ";
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