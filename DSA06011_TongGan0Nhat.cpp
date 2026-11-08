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
    for (int& x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    int ans = a[i] + a[j];
    while (i < j) {
        int sum = a[i] + a[j];
        if (abs(sum) < abs(ans) || (abs(sum) == abs(ans) && sum < ans)) {
            ans = sum;
        }
        if (sum < 0) {
            ++i;
        } else if (sum > 0) {
            --j;
        } else {
            break;
        }
    }

    cout << ans << NL;
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