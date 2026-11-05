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
    vector<int> a(n), f(1e7, 0);
    for (int& x : a) {
        cin >> x;
        ++f[x];
    }
    int lim1 = *min_element(a.begin(), a.end());
    int lim2 = *max_element(a.begin(), a.end());
    int res = 0;
    for (int i = lim1; i <= lim2; ++i) {
        if (f[i] == 0) {
            ++res;
        }
    }
    cout << res;
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