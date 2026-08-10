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
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        for (int& x : a) {
            cin >> x;
        }
        int i = k - 1;
        while (i >= 0 && a[i] == n - k + i + 1) {
            --i;
        }
        if (i >= 0) {
            ++a[i];
            for (int j = i + 1; j < k; ++j) {
                a[j] = a[j - 1] + 1;
            }
        } else {
            for (int j = 0; j < k; ++j) {
                a[j] = j + 1;
            }
        }
        for (int x : a) {
            cout << x << " ";
        }
        cout << NL;
    }

    return 0;
}