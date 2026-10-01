#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m;
constexpr int a[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        int res = 0;
        for (const int x : a) {
            res += (n / x);
            n %= x;
        }
        cout << res << NL;
    }
    return 0;
}