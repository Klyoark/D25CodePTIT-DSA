#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m;
vector<int> a;
vector<vector<int>> res;
bool ok;

void out(vector<int>& b) {
    cout << "{";
    for (int i = 0; i < b.size(); ++i) {
        cout << b[i];
        if (i != b.size() - 1) {cout << " ";}
    }
    cout << "} ";
}

void solve(int sum, int lim, vector<int> b) {
    if (sum == k) {
        ok = true;
        res.push_back(b);
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] >= lim && sum + a[i] <= k) {
            b.push_back(a[i]);
            solve(sum + a[i], a[i], b);
            b.pop_back();
        }
    }
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        ok = false;
        res.clear();
        cin >> n >> k;
        a.resize(n);
        for (int& x : a) {
            cin >> x;
        }
        sort(a.begin(), a.end());
        solve(0, 0, {});
        if (!ok) {cout << -1;} else {cout << res.size() << " "; for (vector<int>& b : res) {out(b);}}
        cout << NL;
    }
    return 0;
}