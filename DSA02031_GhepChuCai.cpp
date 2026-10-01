#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m;
vector<bool> v(128);
char C;
string s;

bool pa(char c) {
    return (c != 'A' && c != 'E');
}

void solve(char a) {
    if (s.size() == C - 'A' + 1) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'A' || s[i] == 'E') {
                if (i > 0 && i < s.size() - 1 && pa(s[i - 1]) && pa(s[i + 1])) {
                    return;
                }
            }
        }
        cout << s << NL;
        return;
    }


    for (char b = 'A'; b <= C; ++b) {
        if (!v[b]) {
            v[b] = true;
            s.push_back(b);
            solve(a + 1);
            v[b] = false;
            s.pop_back();
        }
    }
}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        s = "";
        v.assign(128, false);
        cin >> C;
        solve('A');
    }
    return 0;
}