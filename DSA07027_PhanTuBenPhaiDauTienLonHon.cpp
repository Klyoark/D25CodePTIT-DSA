#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m; constexpr int MOD = 1e9 + 7;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    stack<int> st;
    vector<int> r(n);
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[i] >= st.top()) {
            st.pop();
        }
        if (st.empty()) {
            r[i] = -1;
        } else {
            r[i] = st.top();
        }
        st.push(a[i]);
    }

    for (int x : r) {
        cout << x << " ";
    }
    cout << NL;
}
int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}