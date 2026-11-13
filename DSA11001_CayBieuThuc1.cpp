//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

bool isOP(const char& c) {
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

void solve() {
    string s;
    cin >> s;
    stack<string> st;
    for (char c : s) {
        string tmp = "";
        if (isOP(c)) {
            string y = st.top(); st.pop();
            string x = st.top(); st.pop();
            tmp += x + c + y;
        } else {
            tmp += c;
        }
        st.push(tmp);
    }
    cout << st.top();
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