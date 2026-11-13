//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
constexpr char NL = '\n';
using namespace std;
constexpr int MOD = 1e9 + 7;

vector<int> posIn(1e5 + 1);
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {};
};

Node* build(const vector<int>& level)    {
    if (level.empty()) return nullptr;

    Node* root = new Node(level[0]);
    int idx = posIn[root->data];

    vector<int> leftlv, rightlv;
    for (int i = 1; i < level.size(); ++i) {
        if (posIn[level[i]] < idx) {
            leftlv.push_back(level[i]);
        } else {
            rightlv.push_back(level[i]);
        }
    }
    root->left = build(leftlv);
    root->right = build(rightlv);
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
    vector<int> in(n), level(n);
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
        posIn[in[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> level[i];
    } 
    Node* root = build(level);
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