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

    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j > 0 && a[j] < a[j - 1]) {
            swap(a[j], a[j - 1]);
            j--;
        }
        vector<int> temp(a.begin(), a.begin() + i + 1);
        res.push_back(temp);
    }

    for (int i = res.size() - 1; i >= 0; --i) {
        cout << "Buoc " << i << ": ";
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << NL;
    }
}
int main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        cout << NL;
    }
    return 0;
}