//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {};
};
vector<int> a;

Node* build(vector<int>& a, int& idx, int bound) {
    if (idx == a.size() || a[idx] > bound) {
        return nullptr;
    }
    Node* root = new Node(a[idx++]);
    root->left = build(a, idx, root->data);
    root->right = build(a, idx, bound);
    return root;
}
void out(Node* root) {
    if (root == nullptr) {
        return;
    }
    out(root->left);
    out(root->right);
    cout << root->data << " ";
}
void solve() {
    int n;
    cin >> n;
    a.resize(n);
    for (int& x : a) {
        cin >> x;
    }
    int idx = 0;
    Node* root = build(a, idx, INT_MAX);
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