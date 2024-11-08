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
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> tresult;
    if (root->left != nullptr)
    {
        tresult = inorderTraversal(root->left);
    }
    tresult.push_back(root->val);
    if (root->right != nullptr)
    {
        vector<int> temp = inorderTraversal(root->right);
        for (unsigned int i = 0; i < temp.size(); i++)
        {
            tresult.push_back(temp[i]);
        }
    }
    return tresult;
}