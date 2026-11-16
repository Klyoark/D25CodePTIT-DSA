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
void add(Node*& root, int data) {
    if (root == nullptr) {
        root = new Node(data);
    } else {
        if (data < root->data) {
            add(root->left, data);
        } else {
            add(root->right, data);
        }
    }
}
int res;
void go(Node* root) {
    if (root == nullptr) {
        return;
    }
    if (root->left || root->right) ++res;
    go(root->left);
    go(root->right);
}
void solve() {
    int n;
    cin >> n;
    Node* root = nullptr;
    while (n--) {
        int x;
        cin >> x;
        add(root, x);
    }
    go(root);
    cout << res;
}
int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        res = 0;
        solve();
        cout << NL;
    }
    return 0;
}