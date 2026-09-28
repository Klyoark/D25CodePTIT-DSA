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
        cin >> n >> k;
        vector<int> a(n);
        ll s = 0;
        for (int& x : a) {
            cin >> x;
            s += x;
        }
        sort(a.begin(), a.end());
        k = min(k, n - k);
        for (int i = 0; i < k; ++i) {
            s -= 2 * a[i];
        }

        cout << s << NL;
    }
    return 0;
}