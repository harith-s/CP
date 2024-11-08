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

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
        return false;
    if (targetSum == root->val && root->left == nullptr && root->right == nullptr)
        return true;

    bool is_sum_l = false;
    bool is_sum_r = false;
    if (root->left)
        is_sum_l = hasPathSum(root->left, targetSum - root->val);
    if (root->right)
        is_sum_r = hasPathSum(root->right, targetSum - root->val);

    return (is_sum_l || is_sum_r);
}

// vector<int> root_leaf(TreeNode *root, int targetSum)
// {
//     vector<int> v;
//     vector<int> temp;
//     if (hasPathSum(root, targetSum))
//     {
//         v.push_back(root->val);
//         if (hasPathSum(root->left, targetSum))
//         {
//             temp = root_leaf(root->left, targetSum - root->val);
//             v.insert(v.end(), temp.begin(), temp.end());
//         }
//         else if (hasPathSum(root->right, targetSum))
//         {
//             temp = root_leaf(root->left, targetSum - root->val);
//             v.insert(v.end(), temp.begin(), temp.end());
//         }
//     }
// }
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
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> result;
    vector<vector<int>> temp;
    vector<int> dummy;
    root_leaf(root, dummy, temp);
    for (int i = 0; i < temp.size(); i++){
        int sum = 0;
        for (int j = 0; j < temp[i].size(); j++){
            sum += temp[i][j];
        }
        if (sum == targetSum){
            result.push_back(temp[i]);;
        }
    }
    return result;
    // vector<int> v;
    // if (hasPathSum(root, targetSum))
    //     v.push_back(root->val);
    // if (hasPathSum(root->left, targetSum))
    //     temp = pathSum(root->left, targetSum - root->val);
    // else
    //     return result;
}