#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m, s;

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        string str;
        cin >> k >> str;
        vector<int> f(500, 0);
        int maxx = 0;

        for (char c : str) {
            ++f[c];
            maxx = max(maxx, f[c]);
        }

        if (maxx <= (str.length() + k - 1) / k) {
            cout << 1 << NL;
        } else {
            cout << -1 << NL;
        }
    }
    return 0;
}