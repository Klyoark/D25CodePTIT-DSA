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
        string g = s;
        g[0] = s[0];
        for (int i = 1; i < s.size(); ++i) {
            g[i] = (s[i] == s[i - 1]) ? '0' : '1';
        }
        cout << g << NL;
    }

    return 0;
}
