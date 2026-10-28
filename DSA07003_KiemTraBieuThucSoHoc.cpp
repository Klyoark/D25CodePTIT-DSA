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
    getline(cin >> ws, s);
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ')') {
            st.push(s[i]);
        } else {
            bool ok = false;
            while (!st.empty()) {
                char c = st.top(); st.pop();
                if (c == '+' || c == '-' || c == '*' || c == '/') {
                    ok = true;
                }
                if (c == '(') {
                    break;
                }
            }
            if (!ok) {
                cout << "Yes" << NL;
                return;
            }
        }
    }
    cout << "No" << NL;
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