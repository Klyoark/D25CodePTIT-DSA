#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k;
vector<int> a, f;

bool hv() {
    int i = n - 2, j = n - 1;
    while (i >= 0 && f[i] >= f[i + 1]) {
        --i;
    }
    if (i < 0) {
        return false;
    }
    while (j >= 0 && f[j] <= f[i]) {
        --j;
    }
    swap(f[i], f[j]);
    reverse(f.begin() + i + 1, f.end());
    return true;
}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (int& x : a) {
            cin >> x;
        }
        f.resize(n);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            cout << a[f[i]] << " ";
        }
        cout << NL;
        while (hv()) {
            for (int i = 0; i < n; ++i) {
                cout << a[f[i]] << " ";
            }
            cout << NL;
        }
    }
    return 0;
}