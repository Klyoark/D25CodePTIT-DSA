#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m; constexpr int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    stack<char> st;
    int open = 0, close = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            ++open;
            st.push(s[i]);
        } else {
            if (!st.empty() && st.top() == '(') {
                st.pop();
                --open;
            } else {
                ++close;
                st.push(s[i]);
            }
        }
    }
    int ans = 0;
    ans += close / 2 + open / 2; // each pair of mismatch only needs 1 flip
    ans += close % 2 + open % 2; //each pair of opposites needs both flipped
    cout << ans << NL;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}