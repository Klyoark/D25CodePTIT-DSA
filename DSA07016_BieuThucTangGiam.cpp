//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    stack<int> st;
    for (int i = 0; i <= s.size(); ++i) {
        st.push(i + 1);
        if (i == s.size() || s[i] == 'I') {
            while (!st.empty()) {
                int j = st.top(); st.pop();
                cout << j;
            }
        }
    }     
}
int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << NL;
    }
    return 0;
}