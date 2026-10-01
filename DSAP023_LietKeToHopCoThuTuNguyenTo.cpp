#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, stt = 1;
vector<int> a;
bool f(int m) {
    if (m < 2) {
        return false;
    }
    if (m <= 3) {
        return true;
    }
    if (m % 2 == 0 || m % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= m; i += 6) {
        if (m % i == 0 || m % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void pr() {
    cout << stt << ":" << " ";
    for (int x : a) {
        cout << x << " ";
    }
    cout << NL;
}
bool th() {
    int i = k - 1;
    while (i >= 0 && a[i] == n -k + i + 1) {
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

    cin >> n >> k;
    a.resize(k);
    for (int i = 0; i < k; ++i) {
        a[i] = i + 1;
    }
    while (th()) {
        ++stt;
        if (f(stt)) {
            pr();
        }
    }

    return 0;
}