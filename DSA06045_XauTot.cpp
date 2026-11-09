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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> chunk;
    ll cnt = 1;

    for (ll i = 1; i <n ; ++i) {
        if (s[i] == s[i - 1]) {
            ++cnt;
        } else {
            chunk.push_back(cnt);
            cnt = 1;
        }
    }
    chunk.push_back(cnt);

    ll sum = n * (n + 1) / 2;
    ll bad = n;

    if (chunk.size() > 1) {
        for (int i = 0; i < chunk.size() - 1; ++i) {
            ll x = chunk[i];
            ll y = chunk[i + 1];
            bad += (x + y -1);
        }
    }
    cout << sum - bad;
}
int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
        cout << NL;
    }
    return 0;
}