#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, ans = 0;
vector<int> a, res;

void pr() {
    for (int x : res) {
        cout << x << " ";
    }
    ++ans;
    cout << NL;
}

void solve(int i, int sum) {
    if (sum == k) {
        pr();
        return;
    }
    if (sum > k || i == n) {
        return;
    }
    solve(i + 1, sum);
    res.push_back(a[i]);
    solve(i + 1, sum + a[i]);
    res.pop_back();
}

int main() {
    fastio;

    cin >> n >> k;
    a.resize(n);
    res.reserve(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve(0, 0);
    cout << ans;


    return 0;
}