#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, s, p;
vector<uint8_t> f(201, 1);
vector<int> pr;
vector<vector<int>> res;
void sieve() {
    f[0] = f[1] = 0;
    for (int i = 2; i * i <= 200; ++i) {
        if (f[i]) {
            for (int j = i * i; j <= 200; j += i) {
                f[j] = 0;
            }
        }
    }
    for (int i = 2; i < 201; ++i) {
        if (f[i]) {
            pr.push_back(i);
        }
    }
}

void solve(int pos, int sum, vector<int>& a) {
    if (a.size() == n) {
        if (sum == s) {
            res.push_back(a);
        }
        return;
    }

    for (int i = pos; i < pr.size(); ++i) {
        if (sum + pr[i] <= s) {
            a.push_back(pr[i]);
            solve(i + 1, sum + pr[i], a);
            a.pop_back();
        } else {
            break;
        }
    }
}

int main() {
    fastio;

    pr.reserve(200);
    sieve();
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n >> p >> s;
        res.clear();
        vector<int> a;
        for (int i = 0; i < pr.size(); ++i) {
            if (pr[i] > p) {
                solve(i, 0, a);
                break;
            }
        }
        sort(res.begin(), res.end());
        cout << res.size() << NL;
        for (vector<int>& a : res) {
            for (int x : a) {
                cout << x << " ";
            }
            cout << NL;
        }
    }
    return 0;
}