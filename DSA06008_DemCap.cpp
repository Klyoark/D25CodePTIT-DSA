//#pragma GCC optimize("O3,unroint-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

void solve() {
    int n , m;
    cin >> n >> m;
    vector<int> x(n), y(m);
    vector<int> f5(5, 0);
    for (int& i : x) {
        cin >> i;
    }
    for (int& i : y) {
        cin >> i;
        if (i < 5) {
            ++f5[i];
        }
    }
    sort(y.begin(), y.end());
    int res = 0;
    for (int i : x) {
        if (i == 0) continue;
        if (i == 1) {
            res += f5[0];
            continue;
        }
        res += y.end() - upper_bound(y.begin(), y.end(), i);
        res += f5[0] + f5[1];
        if (i == 2) {
            res -= f5[3] + f5[4]; 
        }
        if (i == 3) {
            res += f5[2];
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