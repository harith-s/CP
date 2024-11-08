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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
void inOrderWalk(TreeNode *root, int &max_so_far, bool &is_valid)
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
        if (root->val == INT_MIN && root->left == nullptr) {
            return root->right != nullptr ? isValidBST(root->right) && (root->val != root->right->val) : true;
        }
        bool is_valid = true;
        int max = INT_MIN;
        inOrderWalk(root, max, is_valid);
        return is_valid;
    }


int main()
{
    TreeNode *root = new TreeNode;
    TreeNode *a = new TreeNode;
    TreeNode *b;
    TreeNode *c;
    TreeNode *d;
    root->val = INT_MAX;
    a->val = INT_MIN;
    // b->val = 1;
    // c->val = 3;
    // d->val = 6;
    root->left = a;
    // root->right = b;
    // b->left = c;
    // b->right = d;
    cout << isValidBST(root);
}