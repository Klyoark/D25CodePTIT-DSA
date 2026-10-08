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
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        ll res = 0, na = 0, nb = 0;
        for (char c : a) {
            na = na * 2 + (c -'0');
        }
        for (char c : b) {
            nb = nb * 2 + (c - '0');
        }

        cout << 1LL * na * nb << NL;
    }
    return 0;
}