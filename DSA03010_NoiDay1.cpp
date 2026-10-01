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
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; ++i) {
            cin >> k;
            pq.push(k);
        }

        ll res = 0;
        while (pq.size() > 1) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();

            res += x + y;
            
            pq.push(x + y);
        }

        cout << res << NL;
    }
    return 0;
}