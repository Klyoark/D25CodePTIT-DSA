//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

int open(string& s, int l, int r) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
        --l; ++r;
    }
    return r - l - 1;
}

void solve() {
    string s;
    cin >> s;
    int maxl = 0;

    int n = s.size();
    for (int i = 0; i < n; ++i) {
        int l1 = open(s, i, i);
        int l2 = open(s, i, i + 1);
        
        maxl = max({maxl, l1, l2});
    }
    cout << maxl << NL;
}
int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}