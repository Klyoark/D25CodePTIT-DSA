#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k;

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int& x : a) {
            cin  >> x;
        }
        for (int i = 1; i < n; ++i) {
            bool ok = true;
            for (int j = 0; j < n - i; ++j) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                    ok = false;
                }
            }
            if (ok) { 
                break;
            }

            cout << "Buoc " << i << ": ";
            for (int j = 0; j < n; ++j) {
                cout << a[j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}