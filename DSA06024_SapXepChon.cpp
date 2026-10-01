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
    int t = 1;
    //cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        k = n;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
        }
        for (int i = 0; i < n - 1; ++i) {
            int idx = i;
            for (int j = i + 1; j < n; ++j) {
                if (a[j] < a[idx]) {
                    idx = j;
                }
            }
            swap(a[idx], a[i]);
            cout << "Buoc " << i + 1 << ": ";
            for (int x : a) {
                cout << x << " ";
            }
            cout << NL;
        }
    }
    return 0;
}