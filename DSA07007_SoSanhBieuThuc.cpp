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
    string a, b;
    cin >> a >> b;
    stack<int> sign;
    sign.push(1);
    vector<int> fa(26, 0), fb(26, 0);
    char last = '+';

    //a
    for (char c : a) {
        if (c == '+' || c == '-') {
            last = c;
        } else if (c == '(') {
            sign.push(last == '-' ? -sign.top() : sign.top());
            last = '+';
        } else if (c >= 'a' && c <= 'z') {
            fa[c - 'a'] += (last == '-' ? -sign.top() : sign.top());
            last = '+';
        } else if (c == ')') {
            sign.pop();
        }
        
    }
    //b
    for (char c : b) {
        if (c == '+' || c == '-') {
            last = c;
        } else if (c == '(') {
            sign.push(last == '-' ? -sign.top() : sign.top());
            last = '+';
        } else if (c == ')') {
            sign.pop();
        }
        else if (c >= 'a' && c <= 'z') {
            fb[c - 'a'] += (last == '-' ? -sign.top() : sign.top());
            last = '+';
        }
    }
    if (fa == fb) cout << "YES"; else cout << "NO";
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