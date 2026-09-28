#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m;
void solve(char a, char b, char c, int n) {
    if (n == 1) {
        cout << a << " -> " << c << NL;
        return;
    }

    solve(a, c, b, n - 1);
    solve(a, b, c, 1);
    solve(b, a, c, n - 1);
}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        cin >> n;
        solve('A', 'B', 'C', n); //src - aux - dest
    }
    return 0;
}