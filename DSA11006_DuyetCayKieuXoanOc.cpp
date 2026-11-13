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

void insert(Node* root, int n1, int n2, char c) {
    if (root == nullptr) return;
    if (root->data == n1) {
        make(root, n1, n2, c);
    } else {
        if (root->left != nullptr) insert(root->left, n1, n2, c);
        if (root->right != nullptr) insert(root->right, n1, n2, c);
    }
}

void travel(Node* root) {
    if (root == nullptr) return;

    stack<Node*> s1;
    stack<Node*> s2;
    
    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node* t = s1.top(); s1.pop();
            cout << t->data << " ";
            if (t->right != nullptr)s2.push(t->right);
            if (t->left != nullptr) s2.push(t->left);
        } 
        while (!s2.empty()) {
            Node* t = s2.top(); s2.pop();
            cout << t->data << " ";
            if (t->left != nullptr) s1.push(t->left);
            if (t->right != nullptr) s1.push(t->right);
        }
    }
}

void solve() {
    int n;
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

    travel(root);
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