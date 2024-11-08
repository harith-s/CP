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

int sumNumbers(TreeNode *root)
{
    // int sum_l = 0;
    // int sum_r = 0;
    // if (root->left)
    //     sum_l = sumNumbers(root->left);
    // if (root->right)
    //     sum_r = sumNumbers(root->right);

    // if (!(root->left) && !(root->right))
    //     return root->val;
    // else if (root->left && !(root->right))
    //     return root->val * 10 + sum_l;
    // else if (root->left && !(root->right))
    //     return root->val * 10 + sum_r;
    // else
    //     return 2 * (root->val) * 10 + sum_l + sum_r;
}

void sum_to_leaf(TreeNode *root, int &total_sum)
{
    total_sum+= root->val;
    TreeNode* left = root->left;
    TreeNode * right = root->right;
    if (left || right) total_sum *= 10;
    // if (left && right) total_sum *= 2;

    int left_sum = left ? total_sum : 0;
    int right_sum = right ? total_sum : 0;
    if (left) {
        sum_to_leaf(left, left_sum);
    }
    if (right){
        sum_to_leaf(right, right_sum);
    }
    total_sum = (left || right) ? left_sum + right_sum : total_sum;
}