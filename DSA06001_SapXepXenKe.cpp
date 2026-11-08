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
    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n / 2; ++i) {
        cout << a[n - i - 1] << " " << a[i] << " ";
    }
    if (n % 2 != 0) cout << a[n/2];
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