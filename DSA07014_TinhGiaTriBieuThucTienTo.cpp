//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

bool isOp(const char& c) {
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int calc(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': if (b != 0) return a / b;
    }
    return 0;
}

void solve() {
    string exp;
    cin >> exp;
    stack<int> st;
    for (int i = exp.size() - 1; i >= 0; --i) {
        if (isOp(exp[i])) {
            if (st.size() >= 2) {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(calc(a, b, exp[i]));
            } 
        } else {
            st.push((exp[i] - '0'));
        }
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