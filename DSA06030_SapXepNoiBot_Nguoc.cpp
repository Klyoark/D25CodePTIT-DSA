// #pragma GCC optimize("O3,unroll-loops")
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
    vector<vector<int>> res;
    for (int& i : a) cin >> i;

    for (int i = 1; i < n; ++i) {
        bool is_sorted = true;
        for (int j = 0; j < n - i; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                is_sorted = false;
            }
        }
        if (is_sorted) break;
        res.push_back(a);
    }

    for (int i = res.size() - 1; i >= 0; --i) {
        cout << "Buoc " << i + 1 <<": ";
        for (int j = 0; j < n; ++j) {
            cout << res[i][j] << " ";
        }
        cout << NL;
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