#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int mod = 1e9 + 7;
int n, k, m;

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

        sort(a.begin(), a.end());
        ll res = 0;
        for (int i = 0; i < n; ++i) {
            res = (res + a[i] * i) % mod;
        }
        cout << res <<NL;
    }
    return 0;
}