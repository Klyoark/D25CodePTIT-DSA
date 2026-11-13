// #pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

void solve() {
    vector<int> a(1e5 + 1, 0);
    for (int i = 0; i < 2; ++i) {
        string s;
        getline(cin >> ws, s);
        for (char& c : s) {
            if (c == '+') c = ' ';
        }
        stringstream sstr(s);
        string tok;

        while (sstr >> tok) {
            int pos = tok.find('*');
            int cof = stoi(tok.substr(0, pos));
            int exp = stoi(tok.substr(pos + 3));
            a[exp] += cof;
        }
    }

    bool f = true;
    for (int i = 10000; i >= 0; --i) {
        if (a[i] == 0) {
            continue;
        }
        if (!f) cout << " + ";
        cout << a[i] << "*x^" << i;
        f = false;
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