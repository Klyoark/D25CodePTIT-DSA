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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    int i = 0, j = 1;
    ll ans = 0;
    while (i < n && j < n) {
        if (i == j) {
            ++j;
            continue;
        }
        if (a[j] - a[i] < k) {
            ans += j - i;
            ++j;
        } else {
            ++i;
        }
    }
    cout << ans;
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