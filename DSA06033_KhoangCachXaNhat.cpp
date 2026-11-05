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
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    vector<int> L(n), R(n);
    L[0] = a[0];
    R[n - 1] = a[n - 1];
    for (int i = 1; i < n; ++i) {
        L[i] = min(L[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        R[i] = max(R[i + 1], a[i]);
    }
    int i = 0, j = 0, ans = 0;
    while (i < n && j < n) {
        if (L[i] < R[j]) {
            ans = max(ans, j - i);
            ++j;
        } else {
            ++i;
        }
    }
    cout << (ans == 0 ? -1 : ans) << NL;
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