#include <iostream>
#include <vector>

using namespace std;

/**
  Definition for singly-linked list.
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *search_bst(TreeNode *node, int value)
{
    if (node->val == value)
        return node;
    else if (node->left == nullptr && node->right == nullptr)
        return nullptr;
    else if (node->left != nullptr)
    {
        if (node->val > value)
            return search_bst(node->left, value);
        else
            return nullptr;
    }
    else if (node->right != nullptr)
    {
        if (node->val < value)
            return search_bst(node->right, value);
        else
            return nullptr;
    }
}

// TreeNode* search(TreeNode* node, int value){
//     if (node->val == value) return node;
//     else {
//         TreeNode* is_left = node->left != nullptr ? search(node->left, value) : nullptr;
//         TreeNode* is_right = node->right != nullptr ? search(node->right, value) : nullptr;
//         return ;

//     }
// }


class Solution
{
public:
bool fromheresp(ListNode *head, TreeNode *node)
{
    if (head == nullptr)
        return true;
    if (node == nullptr)
        return false;
    else
    {
        TreeNode *l = node->left;
        TreeNode *r = node->right;

        if (head->val == node->val)
            return (fromheresp(head->next, l) || fromheresp(head->next, r));
        else
            return false;
    }
}
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        bool path_from_root= fromheresp(head, root);
        if (path_from_root) return path_from_root;
        else return (isSubPath(head, root->left) || isSubPath(head, root->right));

        
    }
};

// ListNode * lnode = head;
        // if (lnode->val == root->val) {
        //     while(lnode != nullptr){
        //         int value = lnode->val;
        //         // is root starting with the value? check left and right children.
        //         lnode = lnode->next;

        //     }
        // }
        // else{
        //     isSubPath(lnode,root->left);
        //     isSubPath(lnode,root->right);