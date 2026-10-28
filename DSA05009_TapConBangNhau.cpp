#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, sum; constexpr int MOD = 1e9 + 7;
vector<int> a;
bool ok;
void solve(int i, int s) {
    if (i == n || ok || s == sum) {
        if (s == sum / 2) {
            ok = true;
        }
        return;
    }
    if (s + a[i] <= sum / 2) {
        solve(i + 1, s + a[i]);
    }
    solve( i + 1, s);

}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        sum = 0;
        cin >> n;
        a.resize(n);
        for (int& x : a) {
            cin >> x;
            sum += x;
        }
        ok = false;
        if (sum % 2 == 0) {
            solve(0, 0);
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}