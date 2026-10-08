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
        vector<int> a(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            cin >> k;
            a[k] = a[k- 1] + 1;
        }

        cout << n - *max_element(a.begin() + 1, a.end());

        
    }
    return 0;
}