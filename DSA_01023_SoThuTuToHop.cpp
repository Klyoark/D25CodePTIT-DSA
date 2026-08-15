#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, res;
bool check(vector<int>& a, vector<int>& b) {
    if (a != b) {
        return false;
    }
    return true;
}

bool hv(vector<int>& a) {
    int i = k - 1;
    while (i >= 0 && a[i] == n - k  + 1 + i) {
        --i;
    }
    if (i < 0) {
        return false;
    }
    ++a[i];
    for (int j = i + 1; j < k; ++j) {
        a[j] = a[j - 1] + 1;
    }
    return true;
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        res = 1;
        cin >> n >> k;
        vector<int> a(k), b(k);
        for (int& x : a) {
            cin >> x;
        }
        for (int i = 0; i < k; ++i) {
            b[i] = i + 1;
        }
        if (check(a, b)) {
            cout << res << NL;
            continue;
        }
        while (hv(b)) {
            ++res;
            if (check(a, b)) {
                break;
            }
        }
        cout << res << NL;
    }

    return 0;
}