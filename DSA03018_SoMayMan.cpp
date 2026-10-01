#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m, s;

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        //4a + 7b = n; => a = (n - 7b) / 4
        string res = "-1";

        if (n < 4) {
            cout << -1 << NL;
            continue;
        } else if (n == 4) {
            cout << 4 << NL;
            continue;
        } else if (n == 7) {
            cout << 7 << NL;
            continue;
        } else if (n == 8) {
            cout << 44 << NL;
            continue;
        } else {
            int a;
            for (int b = n / 7; b >= 0; --b) {
                int r = n - 7 * b;
                if (r % 4 == 0) {
                    a = r / 4;
                    string tmp;
                    tmp.append(a, '4');
                    tmp.append(b, '7');
                    res = tmp;
                    break;
                }
            }

            cout << res << NL;
        }

    }
    return 0;
}