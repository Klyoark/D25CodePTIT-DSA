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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
        }
        int i = n - 2, j = n - 1;
        while (i >= 0 && a[i] >= a[i + 1]) {
            --i;
        }
        if (i >= 0) {
            while (j >= 0 && a[j] <= a[i]) {
                --j;
            }
            swap(a[i], a[j]);
            reverse(a.begin() + 1 + i, a.end());
        } else {
            for (int i = 0; i < n; ++i) {
                a[i] = i + 1;
            }
        }

        for (int x : a) {
            cout << x << " ";
        }
        cout << NL;
    }

    return 0;
}