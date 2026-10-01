#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m;
vector<bool> v;
vector<int> a;


void solve(int i) {
    if (i == n) {
        for (int j = 0; j < n; ++j) {
            cout << a[j];
        }
        cout << NL;
        return;
    }
    for (int j = 1; j <= n; ++j) {
        if (!v[j]) {
            if (i > 0 && abs(a[i - 1] - j) == 1) continue;
            v[j] = true;
            a[i] = j;

            solve(i + 1);
            v[j] = false;
        }
    }
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        v.assign(n + 1, false);
        solve(0);
    }
    return 0;
}