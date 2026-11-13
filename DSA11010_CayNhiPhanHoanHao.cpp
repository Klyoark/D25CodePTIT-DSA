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
    Node* left, * right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {};
};
void make(Node* root, int n1, int n2, char c) {
    if (root == nullptr) return;
    switch(c) {
        case 'L':
            root->left = new Node(n2);
            break;
        case 'R':
            root->right = new Node(n2);
            break;
    }
}
void insert(Node* root, int n1, int n2, char c) {
    if (root == nullptr) return;
    if (root->data == n1) {
        make(root, n1, n2, c);
    } else {
        if (root->left != nullptr) insert(root->left, n1, n2, c);
        if (root->right != nullptr) insert(root->right, n1, n2, c); 
    }
}

bool ok = false;
int count(Node* node) {
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return 1;
    if (node->left == nullptr || node->right == nullptr) { //is not leaf + only 1 child node
        ok = false;
        return 0;
    }
    return count(node->left) + count(node->right);
}

void solve() {
    int n;
    ok = true;
    cin >> n;
    Node* root = nullptr;
    while (n--) {
        int n1, n2;
        char c;
        cin >> n1 >> n2 >> c;
        if (root == nullptr) {
            root = new Node(n1);
        }
        insert(root, n1, n2, c);
    }
    int cnt1 = count(root->left);
    int cnt2 = count(root->right);
    if (ok && (cnt1 == cnt2)) {
        cout << "Yes";
    } else {
        cout << "No" ;
    }
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