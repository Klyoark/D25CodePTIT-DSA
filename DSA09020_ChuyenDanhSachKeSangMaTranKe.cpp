//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        string s; getline(cin >> ws, s);
        string tok;
        stringstream sstr(s);
        while (sstr >> tok) {
            a[stoi(tok)][i] = 1;
            a[i][stoi(tok)] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << NL;
    }
}
int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
        cout << NL;
    }
    return 0;
}