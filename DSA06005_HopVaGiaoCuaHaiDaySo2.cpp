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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& x : a) {
        cin >> x;
    }
    for (int& x : b) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    set_union(a.begin(), a.end(), b.begin(), b.end(), ostream_iterator<int>(cout, " "));
    cout << NL;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), ostream_iterator<int>(cout, " "));
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