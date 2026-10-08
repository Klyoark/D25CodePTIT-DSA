#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m, s;
constexpr int MOD = 1e9 + 7;

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
        }
        int res = a[0], sum = a[0];
        for (int i = 1; i < n; ++i) {
            sum = max(a[i], sum + a[i]);
            res = max(res, sum);
        }

        cout << res << NL;
    }
    return 0;
}