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

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> result;
    for(int i = 0; i < n; i++){
        TreeNode * root = &TreeNode(i);
        result.push_back(root);
        generateTrees(i - 1);
        generateTrees(n - i);
    }   
}