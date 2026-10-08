#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m, s; constexpr int MOD = 1e9 + 7;

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> k >> a >> b;
        
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res = "";

        while (i >= 0 || j >= 0 || carry) {
            int d = carry;
            if (i >= 0) {d += (a[i]- '0');}
            if (j >= 0) {d += (b[j]- '0');}
            --i, --j;
            res.push_back(char(d % k + '0'));
            carry = d / k;
        }

        reverse(res.begin(), res.end());
        cout << res << NL;
    }
    return 0;
}