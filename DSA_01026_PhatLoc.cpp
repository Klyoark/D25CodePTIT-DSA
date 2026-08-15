#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k;
vector<string> res;

void push(string& s) {
    if (s.front() == '8' && s.back() == '6' && s.find("88") == -1 && s.find("6666") == -1) {
        res.push_back(s);
    }
}

void solve(int pos, string s) {
    if (pos == n) {
        push(s);
        return;
    }
    s[pos] = '6';
    solve(pos + 1, s);
    s[pos] = '8';
    solve(pos + 1, s);  
}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        cin >> n;
        res.reserve(1e5);
        string s;
        s.resize(n);
        solve(0, s);
        sort(res.begin(), res.end());
        for (string& s : res) {
            cout << s << NL;
        }
    }
    return 0;
}