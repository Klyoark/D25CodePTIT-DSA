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
void make(Node* root, int n1, int n2, char c) {
    if (root == nullptr) return;
    switch (c) {
        case 'L':
            root->left = new Node(n2);
            break;
        case 'R':
            root->right = new Node(n2);
            break;
    }
}
bool insert(Node* root, int n1, int n2, char c) {
    if (root == nullptr) return false;

    if (root->data == n1) {
        make(root, n1, n2, c);
        return true;
    }

    if (insert(root->left, n1, n2, c))
        return true;

    if (insert(root->right, n1, n2, c))
        return true;

    return false;
}
ll res = LLONG_MIN;
ll dfs(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return root->data; //leaf
    if (root->right == nullptr) return root->data + dfs(root->left); //L
    if (root->left == nullptr) return root->data + dfs(root->right); //R

    //both, update here cus 2 children, can do leaf->leaf
    ll L = dfs(root->left);
    ll R = dfs(root->right);
    res = max(res, L + R + root->data);
    return root->data + max(L, R);
}
void solve() {
    int n;
    cin >> n;
    Node* root = nullptr;
    res = LLONG_MIN;
    while (n--) {
        int n1, n2;
        char c;
        cin >> n1 >> n2 >> c;
        if (root == nullptr) {
            root = new Node(n1);
        }
        insert(root, n1, n2, c);
    }
    dfs(root);
    cout << res;
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