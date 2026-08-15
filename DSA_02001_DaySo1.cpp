#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k;
vector<int> a, b;

void out() {
    cout << "[";
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i];
        if (i != a.size() - 1) {
            cout << " ";
        }
    }
    cout << "]" << NL;
}

void solve(int max) {
    out();
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
        for (int& x : a) {
            cin >> x;
        }
        solve(n);
    }
    return 0;
}