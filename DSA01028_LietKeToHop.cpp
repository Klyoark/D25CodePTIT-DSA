#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k;
vector<int> a, f;

void pr() {
    for (int i = 0; i < k; ++i) {
        cout << a[f[i]] << " ";
    }
    cout << NL;
}

bool th() {
    int i = k - 1;
    while (i >= 0 && f[i] == n - k + i) {
        --i;
    }
    if (i < 0) {
        return false;
    }
    ++f[i];
    for (int j = i + 1; j < k; ++j) {
        f[j] = f[j - 1] + 1;
    }
    return true;
}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        cin >> n >> k;
        f.resize(k);
        set<int> se;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            se.insert(x);
        }
        a.assign(se.begin(), se.end());
        n = a.size();

        f.resize(k);
        for (int i = 0; i < k; ++i) {
            f[i] = i;
        }

        pr();
        while (th()) {
            pr();
        }
    }
    return 0;
}