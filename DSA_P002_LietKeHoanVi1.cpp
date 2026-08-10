#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, res = 0;
vector<int> a;
void pr() {
    ++res;
    cout << res << ":" << " ";  
    for (int x : a) {
        cout << x << " ";
    }
    cout << NL;
}

bool hv() {
    int i = n - 2, j = n - 1;
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

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    pr();
    while (hv()) {
        pr();
    }

    return 0;
}