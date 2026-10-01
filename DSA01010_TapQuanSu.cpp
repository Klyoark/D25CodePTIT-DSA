#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k;

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(k), bf(k);
        for (int& x : a) {
            cin >> x;
        }
        bf = a;
        int i = k - 1;
        while (i >= 0 && a[i] == n - k + i + 1) {
            --i;
        }
        if (i < 0) {
            cout << k;
        } else {
            ++a[i];
            for (int j = i + 1; j < k; ++j) {
                a[j] = a[j - 1] + 1;
            }
            int p = 0, q = 0, res = 0;
            while (p < k, q < k) {
                if (bf[p] == a[q]) {
                    ++p;
                    ++q;
                } else if (bf[p] < a[q]) {
                    ++p;
                    ++res;
                } else {
                    ++q;
                }
            }
            res += (k - p);
            cout << res;
        }
        cout << NL;
    }

    return 0;
}