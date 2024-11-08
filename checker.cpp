
#include <iostream>
#include <vector>
#include <climits>

using namespace std;
// namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void root_leaf (TreeNode*root, vector<int> v, vector<vector<int>> &result){
    if (root->left == nullptr && root->right == nullptr)
    {   
        v.push_back(root->val);
        result.push_back(v);
    }
    else{
        v.push_back(root->val);
        if (root->left) root_leaf(root->left, v, result);
        if (root->right) root_leaf(root->right, v, result);
    }

}
int main(){
    TreeNode *root = new TreeNode;
    TreeNode *a = new TreeNode;
    TreeNode *b = new TreeNode;
    TreeNode *c = new TreeNode;
    TreeNode *d = new TreeNode;
    root->val = 10;
    a->val = -1;
    b->val = 1;
    c->val = 3;
    d->val = 6;
    root->left = a;
    root->right = b;
    b->left = c;
    b->right = d;

    vector<vector<int>> v;
    vector<int> r;
    root_leaf(root, r, v);
}