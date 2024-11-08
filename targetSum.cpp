#include <iostream>
#include <vector>
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

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (targetSum == 0)
        return true;
    else if (targetSum < 0)
        return false;
    if (root->left && root->right)
        return (hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val));
    else if (root->left)
        return hasPathSum(root->left, targetSum - root->val);
    else if (root->right)
        return hasPathSum(root->right, targetSum - root->val);
    else
        return false;
}