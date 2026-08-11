#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

vector<string> solve(int n){
    if (n == 1) {
        return {"0", "1"};
    }
    vector<string> b = solve(n - 1);
    vector<string> res;

    int m = b.size();
    for (int i = 0; i < m; ++i) {
        res.push_back("0" + b[i]);
    }
    for (int i = m - 1; i >= 0; --i) {
        res.push_back("1" + b[i]);
    }
    return res;
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;   
        vector<string> ans = solve(n);
        for (const string& s : ans) {
            cout << s << " ";
        }
        cout << NL;
    }

    return 0;
}