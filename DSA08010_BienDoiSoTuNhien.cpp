//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

unordered_set<int> vis;
vector<pair<int, int>> q;

ll n, k, m; constexpr int MOD = 1e9 + 7;
void solve() {
    cin >> n;
    if (n <= 2) {cout << n - 1 << NL; return;}

    q.clear();
    vis.clear();

    
    int head = 0;
    q.push_back(make_pair(n, 0));
    int res = -1;

    while (res == -1) {
        int x = q[head].first;
        int d = q[head].second;
        ++head;

        if ( x== 2) {
            res = d + 1;
            break;
        }

        //op (a);
        if (vis.insert(x - 1).second) q.push_back(make_pair(x - 1, d + 1));

        //op(b) 
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                int y = x / i;
                if (vis.insert(y).second)  {
                    q.push_back(make_pair(y, d + 1));
                }
            }
        }
    }
    cout << res << NL;
}
int main() {
    fastio;
    q.reserve(1 << 15);
    vis.reserve(1 << 12);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}