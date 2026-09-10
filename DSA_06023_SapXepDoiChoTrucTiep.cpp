#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k, m;
void testCase() {
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[i])
                swap(a[i], a[j]);
        }
        
        cout << "Buoc " + to_string(i + 1) + ": ";
        for (int j = 0; j < n; ++j) {
            cout << a[j] << " ";
        }
        cout << NL;
    }
}

int main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        testCase();
        cout << NL;
    }
    return 0;
}