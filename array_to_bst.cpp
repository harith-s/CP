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

TreeNode *sortedArrayToBST(vector<int> &nums)
{

    int size = nums.size();
    if (size == 2)
    {
        TreeNode *internal = new TreeNode;
        TreeNode * leaf = new TreeNode;
        internal->val = nums[0];
        leaf->val = nums[1];
        internal->right = leaf;
        return internal;
    }
    else if (size == 1)
    {
        TreeNode * leaf = new TreeNode;
        leaf->val = nums[0];
        return leaf;
    }
    else if (size == 0)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode;
    root->val = nums[size / 2]; // when it is odd it is helpful for us and when it is even I will have to figure out.
    vector<int> left;
    left.reserve(size / 2);
   
    vector<int> right;
    right.reserve(size / 2);
    // for (int i = 0; i < size / 2; i++)
    // {
    //     left.push_back(nums[i]);
    // }
    // for (int i = (size / 2) + 1; i < size; i++)
    // {
    //     right.push_back(nums[i]);
    // }
    left.insert(left.end(), nums.begin(), nums.begin() + size /2 - 1);
    right.insert(right.end(), nums.begin() + size /2 + 1, nums.end());

    root->left = sortedArrayToBST(left);
    root->right = sortedArrayToBST(right);
    return root;
}

int main(){
    vector<int> v;
    for (int i = 0; i < 4; i++){
        v.push_back(i);
    }
    sortedArrayToBST(v);
    
}