#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n;
char c;
string s = "";

void solve(char i) {
    if (s.length() == n) {
        cout << s << NL;
        return;
    }
    for (char j = i; j <= c; ++j) {
        s.push_back(j);
        solve(j);
        s.pop_back();
    }
}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        cin >> c >> n;
        solve('A');
    }
    return 0;
}