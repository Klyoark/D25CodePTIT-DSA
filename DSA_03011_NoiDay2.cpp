#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
const int BASE = 1e9 + 7;
int n, k, m, s;

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        for (int i = 0; i < n; ++i) {
            cin >> k;
            pq.push(k);
        }

        ll res = 0;
        while (pq.size() > 1) {
            ll x = pq.top(); pq.pop();
            ll y = pq.top(); pq.pop();

            ll z = (x + y) % BASE;
            res = (res + z) % BASE;
            pq.push(z);
        }

        cout << res << NL;
    }
    return 0;
}