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
    vector<int> b = a;
    sort(b.begin(), b.end());
    int i = 0, j = n - 1;
    while (a[i] == b[i]) {
        ++i;
    }
    while (a[j] == b[j] && j > i) {
        --j;
    }
    cout << i + 1 << " " << j + 1;
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