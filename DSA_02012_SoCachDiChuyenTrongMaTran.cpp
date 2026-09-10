#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, m;
vector<vector<int>> a(11, vector<int>(11));

ll C(int s, int k) {
    if (k > s - k) {
        k = s - k;
    }
    ll res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (s - k + i)/i;
    }
    return res;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        int x;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> x;
            }
        }
        cout << C(m + n - 2, m - 1) << NL;
    }
    return 0;
}