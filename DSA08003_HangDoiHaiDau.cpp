#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m; constexpr int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s;
    int x;
    deque<int> dq;
    while (n--) {
        cin >> s;
        if (s == "PUSHBACK") {
            cin >> x;
            dq.push_back(x);
        }
        else if (s == "PUSHFRONT") {
            cin >> x;
            dq.push_front(x);
        }
        else if (s == "POPBACK") {
            if (!dq.empty())
                dq.pop_back();
        }
        else if (s == "POPFRONT") {
            if (!dq.empty())
                dq.pop_front();
        }
        else if (s == "PRINTFRONT") {
            if (!dq.empty())
                cout << dq.front();
            else
                cout << "NONE";
            cout << NL;
        }
        else if (s == "PRINTBACK") {
            if (!dq.empty())
                cout << dq.back();
            else
                cout << "NONE";
            cout << NL;
        }
    }
}
int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}