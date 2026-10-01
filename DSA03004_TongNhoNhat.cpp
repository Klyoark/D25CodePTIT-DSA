#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

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

        sort(a.begin(), a.end())    ;

        ll x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            x = x * 10 + a[i];
            ++i;
            if (i != n) {
                y = y * 10 + a[i];
            }
        }
        cout << x+y << NL;
    }
    return 0;
}