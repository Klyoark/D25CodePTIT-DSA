#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m; constexpr int MOD = 1e9 + 7;

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

        vector<int> e;
        for (int x : a) {
            auto it = upper_bound(e.begin(), e.end(), x);
            if (it == e.end()) {
                e.push_back(x);
            } else {
                *it = x;
            }
        }
        cout << n - e.size() << NL;
    }
    return 0;
}