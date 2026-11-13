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
    int n;
    string s;
    cin >> n;
    getline(cin >> ws, s);
    queue<int> q;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == ' ') continue;
        if (isdigit(s[i])) {
            string tmp = "";
            while (isdigit(s[i])) {
                tmp = s[i--] + tmp;
            }
            ++i;
            q.push(stoi(tmp));
        } else {
            int y = q.front(); q.pop();
            int x = q.front(); q.pop();
            q.push(calc(x, y, s[i]));
        }
    }
    cout << q.front();
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