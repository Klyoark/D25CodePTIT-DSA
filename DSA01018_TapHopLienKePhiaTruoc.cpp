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
        vector<int> a(k);
        for (int& x : a) {
            cin >> x;
        }
        int i = k - 1;
        while (i >= 0 && (i == 0 ? a[i] == 1 : a[i] == a[i - 1] + 1)) {
            --i;
        }
        if (i >= 0) {
            --a[i];
            for (int j = i + 1; j < k; ++j) {
                a[j] = n - k + j + 1;
            }
        } else {
            for (int i = 0; i < k; ++i){
                a[i] = n - k + i + 1;
            }
        }
        for (int x : a) {
            cout << x << " ";
        }
        cout << NL;
    }

    return 0;
}