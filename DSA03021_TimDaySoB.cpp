#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n; constexpr int MOD = 1e9 + 7;

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
        }
        int mn = *min_element(a.begin(), a.end());
        // ai / bi = k;
        // k <= ai/bi < k + 1
        // kb <= ai < (k+1)b 
        // ==>
        ll best = 1e18;
        int bestK = 0;
        for (int k = 0; k < mn; ++k) {
            ll sum = 0;
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                //right side ai < (k+1)b
                // b > ai/(k+1)
                // or b = ai/(k+1) + 1
                int b = a[i] / (k + 1) + 1;
                //left side kb <= ai
                if (k >= 1 && b > a[i] / k) {
                    ok = false;
                    break;
                }
                sum += b;
            }
            if (ok && sum < best) {
                best = sum;
                bestK = k;
            }
        }
        ll res = 0;
        for (int i = 0; i < n; ++i) {
            res += a[i] / (bestK + 1) + 1;
        }
        cout << res << NL;
    }
    return 0;
}