//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {};
};
Node* add(vector<int>& a, int l, int r) {
    if (l > r) return nullptr;
    int mid = (l + r) / 2;
    Node* root = new Node(a[mid]);
    root->left = add(a, l, mid - 1);
    root->right = add(a, mid + 1, r);
    return root;
}

int res;
int cnt(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return cnt(root->left) + cnt(root->right);
}
void solve() {
    res = 0;
    int n;
    cin >> n;
    Node* root = nullptr;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    root = add(a, 0, n - 1);
    cout << cnt(root);
}
int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << NL;
    }
    return 0;
}