#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL  = '\n';
using namespace std;

int n, k, m, s, sb, sm;

void small() {
    if (s == 0) {
        if (n == 1) {
            cout << 0 ;
        } else {
            cout << -1 ;
        }
        return;
    }

    if (s > 9 * n) {
        cout << -1 ;
        return;
    }


    vector<int> res(n, 0);
    sm = s;
    --sm;

    for (int i = n - 1; i > 0; --i) {
        if (sm > 9) {
            res[i] = 9;
            sm -= 9;
        } else {
            res[i] = sm;
            sm = 0;
        }
    }
    res[0] = sm + 1;
    for (int x : res) {
        cout << x;
    }
}

void big() {
    if (s == 0) {
        if (n == 1) {
            cout << 0 ;
        } else {
            cout << -1;
        }
        return;
    }

    if (s > 9 * n) {
        cout << -1 ;
        return;
    }


    vector<int> res(n, 0);
    sm = s;
    for (int i = 0; i < n; ++i) {
        if (sm > 9) {
            res[i] = 9;
            sm -= 9;
        } else {
            res[i] = sm;
            sm = 0;
        }
    }
    for (int x : res) {
        cout << x;
    }
}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        cin >> n >> s;
        small();
        cout << " ";
        big();    
    }
    return 0;
}