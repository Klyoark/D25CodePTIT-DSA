#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n;
vector<char> a;
void pr() {
    for (char c : a) {
        cout << c;
    }
    cout << " ";
}
bool solve() {
    int i = n - 1;
    while (i >= 0 && a[i] == 'B') {
        --i;
    }
    if (i < 0) {
        return false;
    }
    a[i] = 'B';
    for (int j = i + 1; j < n; ++j) {
        a[j] = 'A';
    }
    return true;

}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.assign(n, 'A');
        pr();
        while (solve()) {
            pr();
        }
        cout << NL;
    }

    return 0;
}