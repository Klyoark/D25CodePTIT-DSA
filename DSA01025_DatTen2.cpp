#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k;
vector<char> a;
void pr() {
    for (char c : a) {
        cout << c;
    }
    cout << NL;
}

bool th() {
    int i = k - 1;
    while (i >= 0 && a[i] == 'A' + (n - k + i)) {
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
        cin >> n >> k;
        a.assign(k, 'A');
        for (int i = 0; i < k; ++i) {
            a[i] += i;
        }
        pr();
        while (th()) {
            pr();
        }
    }

    return 0;
}