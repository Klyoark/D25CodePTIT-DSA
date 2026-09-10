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
    // cin >> t;
    while (t--) {
        int x;
        string s;
        vector<int> a;
        while (cin >> s) {
            if (s == "push") {
                cin >> x;
                a.push_back(x);
            } else if (s == "pop") {
                if (!a.empty()) {
                    a.pop_back();
                }
            } else if (s == "show") {
                if (a.empty()) {
                    cout << "empty";
                } else {
                    for (int i : a) cout << i << " ";
                }
                cout << NL;;
            }
        }
    }
    return 0;
}