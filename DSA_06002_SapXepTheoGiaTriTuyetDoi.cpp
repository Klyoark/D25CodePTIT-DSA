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
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
        }
        stable_sort(a.begin(), a.end(), [](int a, int b) {
            int ax =  abs(k - a);
            int bx = abs(k - b);    
            return ax < bx;
        });

        for (int x : a) {
            cout << x << " ";
        }
        cout << NL;
    }
    return 0;
}