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
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<ll> a(n1), b(n2), c(n3);
    for (ll& x : a) {
        cin >> x;
    }
    for (ll& x : b) {
        cin >> x;
    }
    for (ll& x : c) {
        cin >> x;
    }
    int i = 0, j = 0, k = 0;
    vector<ll> res;
    while (i < n1 && j < n2 && k < n3) {
        if (a[i] == b[j] && a[i] == c[k]) {
            res.push_back(a[i]);
            ++i; ++j; ++k;
        } else if (a[i] < b[j]) {
            ++i;
        } else if (b[j] < c[k]) {
            ++j;
        } else {
            ++k;
        }
    }
    if (res.empty()) {
        cout << -1;
    } else {
        for (ll x : res) {
            cout << x <<  " ";
        }
    }
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