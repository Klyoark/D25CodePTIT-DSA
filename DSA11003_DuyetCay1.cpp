// #pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;
vector<int> posIn(10001, 0);
int preIdx;
vector<int> pre;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {};
};
Node* build(int l, int r) {
    if (l > r) return nullptr;

    Node* root = new Node(pre[preIdx++]);
    int idx = posIn[root->data];

    root->left = build(l, idx - 1);
    root->right = build(idx + 1, r);
    return root;
}

void out(Node* root) {
    if (root == nullptr) return;
    out(root->left);
    out(root->right);
    cout << root->data << " ";
}

void solve() {
    int n;
    cin >> n;
    vector<int> in(n);
    pre.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
        posIn[in[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> pre[i];
    }
    preIdx = 0;
    Node* root = build(0, n - 1);
    out(root);
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