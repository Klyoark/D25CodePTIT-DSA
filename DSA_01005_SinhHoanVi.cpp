#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long
constexpr char NL = '\n';
using namespace std;

bool hv(vector<int>& a) {
    int n = a.size() - 1;
    int i = n - 1, j = n;
    while (i >= 0 && a[i] >= a[i + 1]) {
        --i;
    }
    if (i < 0) {
        return false;
    }
    while (a[j] <= a[i]) {
        --j;
    }
    swap(a[i], a[j]);
    reverse(a.begin() + i + 1, a.end());

    return true;
}

void pr(vector<int>& a) {
    for (int x : a) {
        cout << x;
    }
    cout << " ";
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<int> a;
        a.reserve(n + 1);
        for (int i = 1; i <= n; ++i) {
            a.push_back(i);
        }
        pr(a);
        while (hv(a)) {
            pr(a);
        }
        cout << NL;
    }
    return 0;
}