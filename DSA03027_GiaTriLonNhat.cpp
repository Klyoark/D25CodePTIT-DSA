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
    // cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> a(n);

        ll sum = 0;
        for (ll& x : a) {
            cin >> x;
            if (x < 0) {sum += 0;} else {sum += 2 * x;}
        }
        cout << sum << NL;
    }
    return 0;
}