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
    vector<int> a, b;
    int p = 1;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (p) {
            a.push_back(x);
            p ^= 1;
        } else {
            b.push_back(x);
            p ^= 1;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    for (int i = 0; i < n / 2; ++i) {
        cout << a[i] << " " << b[i] << " ";
    }
    if ((n & 1) == 1) {
        cout << a.back();
    }
}
int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
        cout << NL;
    }
    return 0;
}