#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long
constexpr char NL = '\n';
using namespace std;

void pr(vector<int>& a) {
    for (int x : a) {
        cout << x;
    }
    cout << " ";
}

bool th(vector<int>& a, int n, int k) {
    int i = k - 1;
    while (i >= 0 && a[i] == n - k + i + 1) {
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
        int n, k;
        cin >> n >> k;
        vector<int> a;
        a.reserve(k);
        for (int i = 1; i <= k; ++i) {
            a.push_back(i);
        }
        pr(a);
        while (th(a, n, k)) {
            pr(a);
        }
        cout << NL;
    }
    return 0;
}