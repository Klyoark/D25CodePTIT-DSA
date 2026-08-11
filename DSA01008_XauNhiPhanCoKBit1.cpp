#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
int n, k;
vector<int> a;
void pr() {
    for (int x : a) {
        cout << x;
    }
    cout << NL;
}
void solve(int pos, int cnt1) {
    if (pos == n) {
        if (cnt1 == k) {
            pr();
        }
        return;
    }
    if (cnt1 > k) {
        return;
    }
    a[pos] = 0;
    solve(pos + 1, cnt1);
    if (cnt1 + 1 <= k) {
        a[pos] = 1;
        solve(pos + 1, cnt1 + 1);
    }
    a[pos] = 0;
}
int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.assign(n, 0);
        solve(0, 0);
        cout << NL;
    }

    return 0;
}