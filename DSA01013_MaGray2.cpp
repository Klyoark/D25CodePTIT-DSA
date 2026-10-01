#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string b = s;
        b[0] = s[0];
        for (int i = 1; i < b.size(); ++i) {
            s[i] = (s[i - 1] == b[i]) ? '0' : '1';
        }
        cout << s << NL;
    }

    return 0;
}