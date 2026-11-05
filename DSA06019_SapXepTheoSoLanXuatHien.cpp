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
    vector<int> a(n), f(1e6 + 5, 0);
    for (int& x : a) {
        cin >> x;
        ++f[x];
    }
    sort(a.begin(), a.end(), [&](int a, int b){
        if (f[a] == f[b]) {
            return a < b;
        }
        return f[a] > f[b];
    });
    for (int x : a) {
        cout << x << " ";
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