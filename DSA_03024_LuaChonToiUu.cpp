#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m;

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> a(n);
        for (auto& x : a) {
            cin >> x.first >> x.second;
        }

        sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b){
            return a.second < b.second;
        });

        ll cnt = 0;
        ll lfin = -1e9;

        for (auto x : a) {
            if (x.first >= lfin) {
                ++cnt;
                lfin = x.second;
            }
        }
        cout << cnt << NL;
    }
    return 0;
}