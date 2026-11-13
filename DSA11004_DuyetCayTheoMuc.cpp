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
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void make(Node* node, int no1, int no2, char c) {
    switch(c) {
        case 'L':
            node->left = new Node(no2);
            break;
        case 'R':
            node->right = new Node(no2);
            break;
    }
}

void insert(Node* node, int no1, int no2, char c) {
    if (node == NULL) {
        return;
    }
    if (node->data == no1) {
        make(node, no1, no2, c);
    } else {
        insert(node->left, no1, no2, c);
        insert(node->right, no1, no2, c);
    }
}

void travel(Node* root) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* p = q.front(); q.pop();
        cout << p->data << " ";
        if (p->left != NULL) {
            q.push(p->left);
        } 
        if (p->right != NULL) {
            q.push(p->right);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    Node* root = NULL;
    while (n--) {
        int no1, no2;
        char c;
        cin >> no1 >> no2 >> c;
        if (root == NULL) {
            root = new Node(no1);
        }
        insert(root, no1, no2, c);
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