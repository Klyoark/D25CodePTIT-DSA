//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

vector<pair<int, int>> br;
vector<bool> del;
set<string> se;
string s;
void make(int done) {
    if (done == br.size()) {
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (!del[i]) {
                res += s[i];
            }
        }
        if (res != s) {
            se.insert(res);
        }
        return;
    }

    make(done  + 1);


    int l = br[done].first;
    int r = br[done].second;
    del[l] = del[r] = true;
    make(done + 1);
    del[l] = del[r] = false;
}

void solve() {
    cin >> s;
    stack<int> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            int l = st.top();
            st.pop();
            br.push_back(make_pair(l, i));
        }
    }
    del.assign(s.size(), false);
    make(0);

    for (const string& ans : se) {
        cout << ans << NL;
    }
}
int main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        cout << NL;
    }
    return 0;
}