
//  Definition for a binary tree node.

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
class Solution
{
public:
    void inOrderWalk(TreeNode *root, int max_so_far, bool &is_valid)
    {

        if (not(is_valid))
            return;

        if (root->left != nullptr)
            inOrderWalk(root->left, max_so_far, is_valid);
        if (max_so_far >= root->val)
            is_valid = false;
        else
            max_so_far = root->val;
        if (root->right != nullptr)
            inOrderWalk(root->right, max_so_far, is_valid);
    }
    bool isValidBST(TreeNode *root)
    {
        bool is_valid = true;
        int max = INT_MIN;
        inOrderWalk(root, max, is_valid);
        return is_valid;
    }
};

// if (root == nullptr) return true;
//         inOrderWalk(root->left, max_so_far);
//         if (max_so_far > root->val) return false;
//         else max_so_far = root->val;
//         inOrderWalk(root->right, max_so_far);