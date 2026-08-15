#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;

int n, k;
vector<int> tmp;
void pr(vector<string>& a) {
    for (int i = 0; i < k; ++i) {
        cout << a[tmp[i] - 1] << " ";
    }
    cout << NL;
}

bool th() {
    int i = k - 1;
    while (i >= 0 && tmp[i] == n - k + i + 1) {
        --i;
    }
    if (i < 0) {
        return false;
    }
    ++tmp[i];
    for (int j = i + 1; j < k; ++j) {
        tmp[j] = tmp[j - 1] + 1;
    }
    return true;
}

int main() {
    fastio;

    cin >> n >> k;
    set<string> se;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        se.insert(s);
    }
    vector<string> a(se.begin(), se.end());
    n = a.size();
    
    tmp.resize(k);
    for (int i = 0; i < k; ++i) {
        tmp[i] = i + 1;
    }
    pr(a);
    while (th()) {
        pr(a);
    }


    return 0;
}