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
        string x;
        cin >> x;
        int n = x.size();
        int i = n - 1;
        while (i >= 0 && x[i] == '0') {
            --i;
        }
        if (i < 0) {
            for (char& c : x) {
                c = '1';
            }
        } else {
            x[i] = '0';
            for (int j = i + 1; j < n; ++j) {
                x[j] = '1';
            }
        }
        cout << x << NL;
    }

    return 0;
}