#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n;
ll W;
struct val {
    int id;
    ll a, c;
    double r;
};
vector<val> v;
vector<uint8_t> x, XOPT;
ll FOPT = 0;

double bound(int i, ll A, ll C) {
    double bC = C;
    ll bA = A;

    for (int j = i; j < n; ++j) {
        if (bA + v[j].a <= W) {
            bA += v[j].a;
            bC += v[j].c;
        } else {
            bC += (W - bA) * v[j].r;
            break;
        }
    }
    return bC;
}

void solve(int i, ll A, ll C) {
    if (i == n) {
        if (C >= FOPT) {
            FOPT = C;
            for (int j = 0; j < n; ++j) {
                XOPT[v[j].id] = x[j];
            }
        }
        return;
    }

    if (bound(i, A, C) <= FOPT) {
        return;
    }

    x[i] = 0;
    solve(i + 1, A, C);

    if (A + v[i].a <= W) {
        x[i] = 1;
        solve(i + 1, A + v[i].a, C + v[i].c);
    }
    x[i] = 0;
}

int main() {
    fastio;
    
    cin >> n >> W;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].c;
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i].a;
        v[i].id = i;
        v[i].r = (double)v[i].c / v[i].a;
    }
    sort(v.begin(), v.end(), [](val a, val b) {
        return a.r > b.r;
    });
    
    x.assign(n, 0);
    XOPT.assign(n, 0);
    solve(0, 0, 0);

    cout << FOPT << NL;
    for (int x : XOPT) {
        cout << x << " ";
    }
    return 0;
}