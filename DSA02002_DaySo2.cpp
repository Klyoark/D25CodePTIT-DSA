#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k;
vector<int> a, b;
vector<vector<int>> res;

void out(vector<int>& c) {
    cout << "[";
    for (int i = 0; i < c.size(); ++i) {
        cout << c[i];
        if (i != c.size() - 1) {
            cout << " ";
        }
    }
    cout << "] ";
}

void solve(int max) {
    res.push_back(a);
    if (max == 1) {
        return;
    }
    for (int i = 0; i < max - 1; ++i) {
        b.push_back(a[i] + a[i + 1]);
    }
    a = b;
    b.clear();
    solve(max - 1);
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        b.reserve(n);
        res.clear();
        for (int& x : a) {
            cin >> x;
        }
        solve(n);
        reverse(res.begin(), res.end());
        for (vector<int>& c : res) {
            out(c);
        }

        cout << NL;
    }
    return 0;
}