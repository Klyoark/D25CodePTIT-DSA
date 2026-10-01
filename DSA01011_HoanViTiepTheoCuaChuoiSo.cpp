#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int main() {
    fastio;

    int t;
    cin >> t;
    for (int z = 1; z <= t; ++z) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i = s.length() - 2, j = s.length() - 1;
        while (i >= 0 && s[i] >= s[i + 1]) {
            --i;
        }
        if (i < 0) {
            cout << z << " " << "BIGGEST\n";
            continue;
        }
        while (j >= 0 && s[j] <= s[i]) {
            --j;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        cout << z << " " << s << NL;
    }

    return 0;
}