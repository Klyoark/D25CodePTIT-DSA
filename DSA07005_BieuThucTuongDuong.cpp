#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m; constexpr int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    stack<int> st;
    st.push(1);
    char last = '+';
    string res = "";
    for (char c : s) {
        if (c == ' ') continue;
        if (c == '+' || c == '-') {
            last = c;
            if (st.top() == 1) {
                res += c;
            } else {
                res += (c == '+' ? '-' : '+');
            }
        } else if (c == '(') {
            st.push(last == '-' ? -st.top() : st.top());
            last = '+'; //reset, in case of double ((
        } else if (c == ')') {
            st.pop();
        } else {
            res += c;
        }
    }
    cout << res << NL;
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