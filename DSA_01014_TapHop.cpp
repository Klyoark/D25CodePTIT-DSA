#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, s, ans;
void solve(int a, int cnt, int sum) {
    if (cnt == k) {
        if (sum == s) {
            ++ans;
        }
        return;
    }

    if (sum >= s) {
        return;
    }

    for (int i = a; i <= n; ++i) {
        if (sum + i > s) {
            break;
        }
        solve(i + 1, cnt + 1, sum + i);
    }
}

int main() {
    fastio;

    while (cin >> n >> k >> s) {
        if (n == 0 && k == 0 && s == 0) {
            break;
        }
        ans = 0;
        solve(1, 0, 0);
        cout << ans << NL;
    }

    return 0;
}