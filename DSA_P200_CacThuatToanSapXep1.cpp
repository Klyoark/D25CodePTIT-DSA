#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> f(10001, 0);
        for (int& x : a) {
            cin >> x;
            ++f[x];
        }
        for (int i= 0; i < 10001; ++i) {
            while (f[i] > 0) {
                cout << i << " ";
                --f[i];
            }
        }
        cout << NL;
    }

    return 0;
}