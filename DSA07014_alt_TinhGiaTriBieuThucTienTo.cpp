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

int parse(const string& s, int& idx) {
    char c = s[idx++];
    if (!isOp(c)) {
        return (c - '0');
    }
    int a = parse(s, idx);
    int b = parse(s, idx);
    return calc(a, b, c);
}

void solve() {
    string exp;
    cin >> exp;
    int idx = 0;
    cout << parse(exp, idx);
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