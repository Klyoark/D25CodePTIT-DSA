#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;


ll solve(ll n, ll k) {
    if (n == 1) {
        return 1;
    }
    //mid = 2^(n-1) + 1
    ll leftHalf = (1LL << (n - 1)) - 1;
    if (k == leftHalf + 1) {
        return n;
    }
    if (k <= leftHalf) {
        return solve(n - 1, k);
    }
    //right side lfsize+2 -> n
    return solve(n - 1, k - (leftHalf + 1));
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >>  k;
        cout << solve(n, k) << NL;
    }
    return 0;
}