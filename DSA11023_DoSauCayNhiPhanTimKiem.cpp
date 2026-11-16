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
void go(Node* root, int cnt) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) res = max(res, cnt);
    go(root->left, cnt + 1);
    go(root->right, cnt + 1); 
}   

void solve() {
    int n;
    cin >> n;
    res = 0;
    Node* root = nullptr;
    while (n--) {
        int x; cin >> x;
        add(root, x);
    }
    go(root, 0);
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