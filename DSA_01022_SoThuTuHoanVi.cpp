#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int res;
bool check(vector<int>& a, vector<int>& b) {
    if (a != b) {
        return false;
    }
    return true;
}

bool hv(vector<int>& a) {
    int i = a.size() - 2;
    int j = a.size() - 1;
    while (i >= 0 && a[i] >= a[i + 1]) {
        --i;
    }
    if (i < 0) {
        return false;
    }
    while (j >= 0 && a[j] <= a[i])  {
        --j;
    }
    swap(a[i], a[j]);
    reverse(a.begin() + i + 1, a.end());
    return true;
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n;
        res = 1;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& x : a) {
            cin >> x;
        }
        for (int i = 0; i < n; ++i) {
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