#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n;
vector<int> a;
void pr() {
    for (int x : a) {
        cout << x << " ";
    }
    cout << NL;
}
void solve(int pos) {
    for (int v = 0; v <= 1; ++v) { 
        a[pos] = a[n - pos - 1] = v;   
        if (pos == (n - 1) / 2) {
            pr();
        } else {
            solve(pos + 1);
        }
    }
}

int main() {
    fastio;

    cin >> n; 
    a.resize(n);   
    solve(0);

    return 0;
}