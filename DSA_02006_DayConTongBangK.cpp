#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k;
vector<int> a, res;
bool solved;

void solve(int i, ll sum) {
    if (i == n) {
        if (sum == k) {
            solved = true;
            cout << "[";
            for (int j = 0; j < res.size(); ++j) {
                if (j == 0) {
                    cout << res[j] ;
                } else {
                    cout << " " << res[j];
                }
            }
            cout << "] ";
        }
        return;
    }
    if (sum > k) {
        return;
    }
    if (sum + a[i] <= k) {
        res.push_back(a[i]);
        solve(i + 1, sum + a[i]);
        res.pop_back();
    }

    solve(i + 1, sum);
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.resize(n);
        solved = false;
        res.clear();
        res.reserve(n);
        for (int& x : a) {
            cin >> x;
        }
        sort(a.begin(), a.end());
        solve(0, 0);
        if (!solved) {
            cout << -1;
        }
        cout << NL;
    }
    return 0;
}