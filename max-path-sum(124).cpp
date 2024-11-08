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
int maximum(TreeNode *root)
{
    long long int lmax = root->left ? maximum(root->left) : INT64_MIN;
    long long int rmax = root->right ? maximum(root->right) : INT64_MIN;

    if (lmax > root->val)
    {
        if (lmax > rmax)
            return lmax;
        else
            return rmax;
    }
    else{
        if (rmax > root->val) return rmax;
        else return root->val;
    }
}

int maxPathSum(TreeNode *root, bool above_chosen)
{

    long long int lmax = INT64_MIN;
    long long int rmax = INT64_MIN;
    int lval = root->left ? root->left->val : INT64_MIN;
    int rval = root->right ? root->right->val : INT64_MIN;


    if (root->val < 0)
    {
        if (root->left)
            lmax = maxPathSum(root->left, false);
        if (root->right)
            rmax = maxPathSum(root->right, false);

        long long int max = lmax > rmax ? lmax : rmax;
        
        if (max < 0)
        {
            max = maximum(root);
        }
        return max;
    }
    //    1
    //  -2   3
    // 4 3 -6 -7

    else
    {

        if (root->left)
            lmax = maxPathSum(root->left, true);
        if (root->right)
            rmax = maxPathSum(root->right, true);

        long long int max = lmax > rmax ? lmax : rmax;
    
        if (above_chosen == false)
            if (lval > 0 && rval > 0)
                return lmax + root->val + rmax;
            else if (lval > 0)
                return lmax + root->val;
            else if (rval > 0)
                return rmax + root->val;
            else
                return max > root->val ? max : root->val;

        else
        {
            long long int max = lmax > rmax ? lmax : rmax;
            if (max < 0)
                max = 0;
            return root->val + max;
        }
    }
}

int helper(TreeNode * node, int & gmax){
    if (node == nullptr) return 0;

    int left = max(0, helper(node->left, gmax));
    int right = max(0, helper(node->right, gmax));

    gmax = max(gmax, node->val + left + right);
    return node->val + max(left, right);
}

int max(TreeNode * root){
    int gmax = INT_MIN;
    helper(root, gmax);
    return gmax;

}
