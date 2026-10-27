#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m, s; constexpr int MOD = 1e9 + 7;

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n + 4);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end() - 4);
        a[n] = a[0] * a[1];
        a[n + 1] = a[n - 1] * a[n - 2];
        a[n + 2] = a[0] * a[1] * a[n - 1];
        a[n + 3] = a[n - 3] * a[n - 2] * a[n - 1];

        cout << *max_element(a.begin() + n, a.end()) << NL;
    }
    return 0;
}