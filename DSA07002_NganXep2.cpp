#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m; constexpr int MOD = 1e9 + 7;

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        int q;
        cin >> q;
        stack<int> st;
        string x;
        while (q--) {
            cin >> x;
            if (x == "PUSH") {
                int a;
                cin >> a;
                st.push(a);
            } else if (x == "POP") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (x == "PRINT") {
                if (st.empty()) {
                    cout << "NONE" << NL;
                } else {
                    cout << st.top() << NL;
                }
            }
        }
    }
    return 0;
}