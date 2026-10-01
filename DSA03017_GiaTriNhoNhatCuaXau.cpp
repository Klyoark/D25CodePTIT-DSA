#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m, s;
string str;
int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> k >> str;
        vector<int> f(130, 0);
        for (char c : str) {
            ++f[c];
        }
        priority_queue<int> pq;
        for (int i : f) {
            if (i > 0) {
                pq.push(i);
            }
        }

        while (k--) {
            if (pq.empty()) {
                break;
            } 
            m = pq.top(); pq.pop();
            --m;
            pq.push(m);
        }

        ll res = 0;
        while (!pq.empty()) {
            m = pq.top(); pq.pop();
            res += 1LL * m * m;
        }

        cout << res << NL;
    }
    return 0;
}