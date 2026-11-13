//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr ll MOD = 1e9 + 7;

bool isOPs(const string& c) {
    return (c == "+") || (c == "-") || (c == "*") || (c == "/");
}

ll calc(ll a, ll b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': if (b != 0) { return a / b ;}
    }
    return 0;
}

void solve() {
    ll n; cin >> n; string exp;
    getline(cin >> ws, exp);
    stringstream sstr(exp);
    string tok;
    stack<ll> st;
    while (sstr >> tok) {
        if (isOPs(tok)) {
            if (st.size() >= 2) {
                ll b = st.top(); st.pop();
                ll a = st.top(); st.pop();
                st.push(calc(a, b, tok[0]));
            }
        } else {
            st.push(stoll(tok));
        }
    }
    cout << st.top();
}
int main() {
    fastio;
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << NL;
    }
    return 0;
}