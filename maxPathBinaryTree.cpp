#include <iostream>
#include <vector>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void findLeaves(TreeNode *root, vector<TreeNode *> &v)
{
    if (root == nullptr) return;
    v.push_back(root);
    if (root->left != nullptr) findLeaves(root->left, v);
    if (root->right != nullptr) findLeaves(root->right, v);
}
int maxPathSum(TreeNode *root)
{
    vector<TreeNode *> leaves;
}