#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
int n, k, res = 0;
vector<char> a;
vector<vector<char>> ans;

void solve(int pos, int cntA, int run) {
    if (pos == n) {
        if (cntA == k) {
            ++run;
        }
        if (run == 1) {
            ans.push_back(a);
            ++res;
        }
        return;
    }


    a[pos] = 'A';
    solve(pos + 1, cntA + 1, run);

    a[pos] = 'B';
    solve(pos + 1, 0, run + (cntA == k));
}

int main() {
    fastio;

    cin >> n >> k;
    a.assign(n, 'A');
    ans.reserve(n * n);
    solve(0, 0, 0);
    cout << res << NL;
    for (vector<char>& vc : ans) {
        for (char c : vc) {
            cout << c;
        }
        cout << NL;
    }

    return 0;
}