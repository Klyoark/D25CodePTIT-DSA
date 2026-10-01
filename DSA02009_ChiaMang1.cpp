#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, s, ok = 0;
vector<int> a;
vector<bool> v;
void solve(int start, int sum, int count) {
    if (ok) {
        return;
    }
    if (count == k - 1) {
        ok = 1;
        return;
    }
    if (sum == s) {
        solve(0, 0, count + 1);
        return;
    }
    for (int i = start; i < n; ++i) {
        if (!v[i] && sum + a[i] <= s) {
            v[i] = true;
            solve(i + 1, sum + a[i], count);
            v[i] = false;
        }
    }
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        ok = 0, s = 0;
        cin >> n >> k;
        a.resize(n);
        v.assign(n, false);
        int total = 0;
        for (int& x : a) {
            cin >> x;
            total += x;
        }
        if (total % k != 0) {
            cout << 0 << NL;
            continue;
        }
        s = total / k;
        sort(a.begin(), a.end(), [](int a, int b){
            return a > b;
        });
        solve(0, 0, 0);
        cout << (ok ? 1 : 0) << NL;
    }
    return 0;
}