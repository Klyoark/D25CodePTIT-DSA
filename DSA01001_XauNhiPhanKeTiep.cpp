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
        int n = s.size() - 1;
        while (n >= 0 && s[n] =='1') {
            --n;
        }
        if (n >= 0) {
            s[n] = '1';
        }
        for (int i = n + 1; i < s.size(); ++i) {
            s[i] = '0';
        }
        cout << s <<NL;
    }

    return 0;
}